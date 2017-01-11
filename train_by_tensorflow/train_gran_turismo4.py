# Copyright 2015 The TensorFlow Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================

"""Simple, end-to-end, LeNet-5-like convolutional MNIST model example.

This should achieve a test error of 0.7%. Please keep this model as simple and
linear as possible, it is meant as a tutorial for simple convolutional models.
Run with --self_test on the command line to execute a short self-test.
"""
from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import argparse
import gzip
import os
import re
import sys
import time
import random
import copy
import numpy
from six.moves import urllib
from six.moves import xrange  # pylint: disable=redefined-builtin
import tensorflow as tf
from tensorflow.python.framework import graph_util
from scipy.misc import imread, imsave, imresize
from scipy import ndimage


DATA_DIRECTORY = './captured'
IMAGE_WIDTH  = 200
IMAGE_HEIGHT = 66
NUM_CHANNELS = 3
NUM_OUTPUTS  = 1
SEED = 66478
BATCH_SIZE = 8
NUM_EPOCHS = 30
EVAL_FREQUENCY = 100

def extract_frame(filename, num_images):
  print("Extracting:  %s  %4d" % ( filename, num_images ))
  with gzip.open(filename) as bytestream:
    buf = bytestream.read( num_images * IMAGE_WIDTH * IMAGE_HEIGHT * NUM_CHANNELS)
    data = numpy.frombuffer(buf, dtype=numpy.uint8).astype(numpy.uint8)
    data = data.reshape(num_images, IMAGE_HEIGHT, IMAGE_WIDTH, NUM_CHANNELS)
    return data
    
def extract_steering(filename, num_images):
  print("Extracting:  %s  %4d" % ( filename, num_images ))
  with gzip.open(filename) as bytestream:
    buf = bytestream.read( num_images * 4 )
    data = numpy.frombuffer(buf, dtype=numpy.float32).astype(numpy.float32)
    data = data.reshape(num_images,NUM_OUTPUTS)
    return data

def weight_variable(shape):
    return tf.Variable(tf.truncated_normal(shape, stddev=0.1, seed=SEED, dtype=tf.float32))

def bias_variable(shape):
    return tf.Variable(tf.constant(0.1, shape=shape, dtype=tf.float32))

def compute_loss(predictions, key_probabilitys):
  diff = predictions - key_probabilitys
  return tf.reduce_mean( tf.abs( diff ) ).eval()

def main(argv=None):

    #   load training data
    train_data = None
    train_keys = None
    for (path, dir, files) in os.walk(DATA_DIRECTORY):
        for filename in files:
            if bool(re.search('\d{8}_\d{4}_f_\d{4}\.gz',filename)):
                num_images = int(re.findall('\d+', filename)[2])
                filename_f = path + "/" + filename
                filename_s = path + "/" + re.sub('_f_', '_s_', filename)
                if train_data is None:
                    train_data = extract_frame(filename_f, num_images )
                    train_keys = extract_steering(filename_s, num_images )
                else:
                    train_data = numpy.concatenate( ( train_data , extract_frame(filename_f, num_images ) ) , axis=0 )
                    train_keys = numpy.concatenate( ( train_keys , extract_steering(filename_s, num_images ) ) , axis=0 )

    train_size = train_data.shape[0]

    #   shuffle training data
    for step in xrange(train_size):
        ridx = random.randrange(train_size)
        rdata= copy.deepcopy(train_data[step])
        rkey = copy.deepcopy(train_keys[step])
        train_data[step] = copy.deepcopy(train_data[ridx])
        train_keys[step] = copy.deepcopy(train_keys[ridx])
        train_data[ridx] = copy.deepcopy(rdata)
        train_keys[ridx] = copy.deepcopy(rkey) 

    #   build train network
    train_data_node    = tf.placeholder( tf.uint8   , shape=(BATCH_SIZE, IMAGE_HEIGHT, IMAGE_WIDTH, NUM_CHANNELS))  
    train_keys_node    = tf.placeholder( tf.float32 , shape=(BATCH_SIZE, NUM_OUTPUTS) )
    train_drop_out_fnn = tf.placeholder( tf.float32 )
    conv01_weights= weight_variable([5, 5, NUM_CHANNELS, 24])
    conv01_biases = bias_variable([24])
    conv02_weights= weight_variable([5, 5, 24, 36])
    conv02_biases = bias_variable([36])                      
    conv03_weights= weight_variable([5, 5, 36, 48])
    conv03_biases = bias_variable([48])            
    conv04_weights= weight_variable([3, 3, 48, 64])
    conv04_biases = bias_variable([64])            
    conv05_weights= weight_variable([3, 3, 64, 64])
    conv05_biases = bias_variable([64])            
    fc1_weights = weight_variable([1152, 100])
    fc1_biases  = bias_variable([100])
    fc2_weights = weight_variable([100, 50])
    fc2_biases  = bias_variable([50])            
    fc3_weights = weight_variable([50, NUM_OUTPUTS])
    fc3_biases  = bias_variable([NUM_OUTPUTS])            

    def model(name, data, train=False):    
        dataf32 = (tf.to_float(data) - (255.0 / 2.0)) * (1.0 / 255.0)                 
        dataf32_shape = dataf32.get_shape().as_list()              
        
        conv01 = tf.nn.conv2d(dataf32, conv01_weights, strides=[1, 2, 2, 1], padding='VALID')
        relu01 = tf.nn.relu(tf.nn.bias_add(conv01, conv01_biases), name=name+"_conv1")                          
        
        conv02 = tf.nn.conv2d(relu01, conv02_weights, strides=[1, 2, 2, 1], padding='VALID')
        relu02 = tf.nn.relu(tf.nn.bias_add(conv02, conv02_biases), name=name+"_conv2")                          
        
        conv03 = tf.nn.conv2d(relu02, conv03_weights, strides=[1, 2, 2, 1], padding='VALID')
        relu03 = tf.nn.relu(tf.nn.bias_add(conv03, conv03_biases), name=name+"_conv3")    
        
        conv04 = tf.nn.conv2d(relu03, conv04_weights, strides=[1, 1, 1, 1], padding='VALID')
        relu04 = tf.nn.relu(tf.nn.bias_add(conv04, conv04_biases), name=name+"_conv4")
        
        conv05 = tf.nn.conv2d(relu04, conv05_weights, strides=[1, 1, 1, 1], padding='VALID')
        relu05 = tf.nn.relu(tf.nn.bias_add(conv05, conv05_biases), name=name+"_conv5")    
        
        cnn0  = relu05
        cnn_flat = tf.reshape( cnn0, [dataf32_shape[0], 1152] )     
        fnn1 = tf.nn.relu(tf.matmul(cnn_flat, fc1_weights) + fc1_biases, name=name+"_fnn1")
        if train:
            fnn1 = tf.nn.dropout(fnn1, train_drop_out_fnn, seed=SEED)    
        fnn2 = tf.nn.relu(tf.matmul(fnn1, fc2_weights) + fc2_biases, name=name+"_fnn3")    
        fnn3 = tf.add( tf.matmul(fnn2, fc3_weights), fc3_biases, name=name )
        return fnn3
    
    train_prediction = model(name="train_model",data=train_data_node, train=True)
    loss = tf.reduce_mean( tf.square( train_prediction - train_keys_node ), 0 )
    optimizer = tf.train.RMSPropOptimizer(0.001,0.99).minimize(loss)
    
    infer_i  = tf.placeholder(tf.uint8, shape=[1, IMAGE_HEIGHT, IMAGE_WIDTH, NUM_CHANNELS], name="infer_i")
    infer_o  = model(name="infer_o",data=infer_i, train=False)
    
    saver = tf.train.Saver()

    start_time = time.time()
    with tf.Session() as sess:
        tf.initialize_all_variables().run()
    
        if not os.path.exists("models"):
            os.mkdir('models')
        if os.path.exists("models/model.ckpt"):
            print("load : models/model.ckpt")
            tf.train.Saver().restore(sess, "models/model.ckpt")
    
        batch_data = numpy.ndarray(shape=(BATCH_SIZE, IMAGE_HEIGHT, IMAGE_WIDTH, NUM_CHANNELS), dtype=numpy.uint8)    
        batch_keys = numpy.ndarray(shape=(BATCH_SIZE, NUM_OUTPUTS), dtype=numpy.float32)    
    
        for step in xrange(int(NUM_EPOCHS * train_size) // BATCH_SIZE):
    
            ridx = random.randrange(train_size)
            while( train_keys[ridx] >= 1*(-0.25) ):
                ridx = (ridx+1) % train_size
            batch_data[0] = train_data[ridx]
            batch_keys[0] = train_keys[ridx]      
            
            ridx = random.randrange(train_size)
            while( train_keys[ridx] >= 1*(-0.20) ):
                ridx = (ridx+1) % train_size
            batch_data[1] = train_data[ridx]
            batch_keys[1] = train_keys[ridx]        
            
            ridx = random.randrange(train_size)
            while( train_keys[ridx] < 1*(-0.20) or train_keys[ridx] >= 1*(-0.03) ):
                ridx = (ridx+1) % train_size
            batch_data[2] = train_data[ridx]
            batch_keys[2] = train_keys[ridx]        
            
            ridx = random.randrange(train_size)
            while( train_keys[ridx] < 1*(-0.03) or train_keys[ridx] >= 1*( 0.03) ):
                ridx = (ridx+1) % train_size
            batch_data[3] = train_data[ridx]
            batch_keys[3] = train_keys[ridx]        
            
            ridx = random.randrange(train_size)
            while( train_keys[ridx] < 1*(-0.03) or train_keys[ridx] >= 1*( 0.03) ):
                ridx = (ridx+1) % train_size
            batch_data[4] = train_data[ridx]
            batch_keys[4] = train_keys[ridx]      
            
            ridx = random.randrange(train_size)
            while( train_keys[ridx] < 1*( 0.03) or train_keys[ridx] >= 1*( 0.20) ):
                ridx = (ridx+1) % train_size
            batch_data[5] = train_data[ridx]
            batch_keys[5] = train_keys[ridx]      
            
            ridx = random.randrange(train_size)
            while( train_keys[ridx] < 1*( 0.20) ):
                ridx = (ridx+1) % train_size
            batch_data[6] = train_data[ridx]
            batch_keys[6] = train_keys[ridx]      
            
            ridx = random.randrange(train_size)
            while( train_keys[ridx] < 1*( 0.25) ):
                ridx = (ridx+1) % train_size
            batch_data[7] = train_data[ridx]
            batch_keys[7] = train_keys[ridx]
        

            feed_dict = {train_data_node: batch_data,train_keys_node: batch_keys, train_drop_out_fnn:0.7 }
            _, predictions = sess.run( [optimizer, train_prediction], feed_dict=feed_dict )
    
            if step % EVAL_FREQUENCY == 0:
                elapsed_time = time.time() - start_time
                start_time = time.time()
                tf.train.Saver().save(sess, "models/model.ckpt")
                print('Step %d (epoch %.2f), %.1f ms' % (step, float(step) * BATCH_SIZE / train_size, 1000 * elapsed_time / EVAL_FREQUENCY))
                print('Minibatch error: %.6e ' % ( compute_loss(predictions, batch_keys) ) )
                for batch in xrange(BATCH_SIZE):
                    print('(%.3f %.3f) : %.3f' % ( batch_keys[batch], predictions[batch], batch_keys[batch] - predictions[batch] ) )
                sys.stdout.flush()
        

        output_graph_def = graph_util.convert_variables_to_constants(sess, sess.graph_def, ["infer_o"])
        tf.train.write_graph(output_graph_def, 'models/', 'frozen_graph.pb'   , as_text=False)
        #tf.train.write_graph(output_graph_def, 'models/', 'frozen_graph.pbtxt', as_text=True)
        
        infer_test_data = numpy.ndarray(shape=(1, IMAGE_HEIGHT, IMAGE_WIDTH, NUM_CHANNELS), dtype=numpy.uint8)    
        infer_test_keys = numpy.ndarray(shape=(1, NUM_OUTPUTS), dtype=numpy.float32)    
        
        for step in xrange(BATCH_SIZE):
            infer_test_data[0] = batch_data[step]
            infer_test_keys[0] = batch_keys[step]
            predictions_out = sess.run( [infer_o], feed_dict={infer_i: infer_test_data} )
            print('[%d]: (%.3f %.3f) : %.3f' % ( step, infer_test_keys[0], predictions_out[0], infer_test_keys[0] - predictions_out[0] ) )        
            imsave("train_"+str(step)+".png", infer_test_data.reshape(IMAGE_HEIGHT,IMAGE_WIDTH,NUM_CHANNELS) )
    


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '--use_fp16',
        default=False,
        help='Use half floats instead of full floats if True.',
        action='store_true'
    )
    parser.add_argument(
        '--self_test',
        default=False,
        action='store_true',
        help='True if running a self test.'
    )
    
    tf.app.run()
    
    
