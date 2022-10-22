import os
from random import random
from turtle import Turtle
import cv2
import matplotlib.pyplot as plt
import numpy as np
import utils
from os import walk
from os.path import join
from datetime import datetime
import random


def crop(x1, y1, x2, y2, x3, y3, x4, y4, img) :
    """
    This function ouput the specified area (parking space image) of the input frame according to the input of four xy coordinates.
    
      Parameters:
        (x1, y1, x2, y2, x3, y3, x4, y4, frame)
        
        (x1, y1) is the lower left corner of the specified area
        (x2, y2) is the lower right corner of the specified area
        (x3, y3) is the upper left corner of the specified area
        (x4, y4) is the upper right corner of the specified area
        frame is the frame you want to get it's parking space image
        
      Returns:
        parking_space_image (image size = 360 x 160)
      
      Usage:
        parking_space_image = crop(x1, y1, x2, y2, x3, y3, x4, y4, img)
    """
    left_front = (x1, y1)
    right_front = (x2, y2)
    left_bottom = (x3, y3)
    right_bottom = (x4, y4)
    src_pts = np.array([left_front, right_front, left_bottom, right_bottom]).astype(np.float32)
    dst_pts = np.array([[0, 0], [0, 160], [360, 0], [360, 160]]).astype(np.float32)
    #Calculates a perspective transform from four pairs of the corresponding points.
    projective_matrix = cv2.getPerspectiveTransform(src_pts, dst_pts)
    #Applies a perspective transformation to an image.
    croped = cv2.warpPerspective(img, projective_matrix, (360,160))
    return croped


def detect(dataPath, clf, filename):
    """
    Please read detectData.txt to understand the format. 
    Use cv2.VideoCapture() to load the video.gif.
    Use crop() to crop each frame (frame size = 1280 x 800) of video to get parking space images. (image size = 360 x 160) 
    Convert each parking space image into 36 x 16 and grayscale.
    Use clf.classify() function to detect car, If the result is True, draw the green box on the image like the example provided on the spec. 
    Then, you have to show the first frame with the bounding boxes in your report.
    Save the predictions as .txt file (Adaboost_pred.txt), the format is the same as GroundTruth.txt. 
    (in order to draw the plot in Yolov5_sample_code.ipynb)
    
      Parameters:
        dataPath: the path of detectData.txt
      Returns:
        No returns.
    """
    # Begin your code (Part 4)
    #raise NotImplementedError("To be implemented")
    dataPathTXT=os.path.join('.',dataPath,'detectData.txt')
    
    f=open(dataPathTXT,'r')

    num=f.readline()

    coordinate=[]

    for i in range(int(num)):
        data=f.readline()
        list1=[]
        val=''
        for char in data:
            val+=char
            if char==chr(32):
                list1.append(int(val))
                val=''
            if char=='\n':
                list1.append(int(val))
                val=''
        coordinate.append(list1)
        
    f.close()
        
    dataPathVideo=os.path.join('.',dataPath,filename)
    
        
    cap = cv2.VideoCapture(dataPathVideo)
    f=open('Adaboost_pred.txt','w')

    dic = {}
    dic['a'] = list()
    dic['b'] = list()
    dic['c'] = list()

    while(1):
        total = 0
        a = 0
        b = 0
        c = 0
        
        ret, frame = cap.read()
        
        if ret==False:
            break
        
        dic = {}
        dic['a'] = list()
        dic['b'] = list()
        dic['c'] = list()

        for i in range(int(num)):
            frameCroped = crop(coordinate[i][0],coordinate[i][1],coordinate[i][2],coordinate[i][3],coordinate[i][4],coordinate[i][5],coordinate[i][6],coordinate[i][7],frame)
            frameCroped = cv2.cvtColor(frameCroped, cv2.COLOR_BGR2GRAY)
            frameCroped = cv2.resize(frameCroped, (36, 16), interpolation=cv2.INTER_AREA)
            
            if clf.classify(frameCroped)==1:
                f.write('1 ')
                '''
                green_color = (0, 255, 0) # BGR
                pts = np.array([[coordinate[i][0], coordinate[i][1]], [coordinate[i][2], coordinate[i][3]], [coordinate[i][6], coordinate[i][7]], [coordinate[i][4], coordinate[i][5]]], np.int32)
                pts = pts.reshape((4, 1, 2))# 將座標轉為 (頂點數量, 1, 2) 的陣列
                cv2.polylines(frame, [pts], True, green_color, 1)# 繪製多邊形
                '''
                                           
            else:
                if(i < 26):
                    a += 1
                    dic['a'].append(i+1)
                elif(i >= 26 and i <= 51):
                    b += 1
                    dic['b'].append(i%26 + 1)
                else:
                    c += 1
                    dic['c'].append(i%26 + 1)
                total += 1
                f.write('0 ')
        #cv2.imshow('detectedImage',frame)
        #print('[Remaining free parking lots]')
        #print('Section A: ', a)
        #print('Section B: ', b)
        #print('Section C: ', c)
        r = random.randint(1,10)
        if r == 10:
            return a, b, c, total, dic
     
        #f.write('\n')
            
        if cv2.waitKey(30) == 27:
            break
    
    
    
    f.close()
    cv2.destroyAllWindows()
    cap.release()

    
    
    
    # End your code (Part 4)
