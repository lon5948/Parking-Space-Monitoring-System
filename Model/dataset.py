import os
import cv2
import numpy as np


def loadImages(dataPath):
    """
    Load all Images in the folder and transfer a list of tuples. 
    The first element is the numpy array of shape (m, n) representing the image.
    (remember to resize and convert the parking space images to 36 x 16 grayscale images.) 
    The second element is its classification (1 or 0)
      Parameters:
        dataPath: The folder path.
      Returns:
        dataset: The list of tuples.
    """
    # Begin your code (Part 1)
    #raise NotImplementedError("To be implemented")
    
    

    dataset=[]
    
    fileRoute=os.getcwd()
    fileRoute=os.path.join(fileRoute,dataPath,'car')
    

    for imgName in os.listdir(fileRoute):
        imgName=os.path.join(fileRoute,imgName)
        img=cv2.imread(imgName)
        
        
        img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        img = cv2.resize(img, (36, 16), interpolation=cv2.INTER_AREA)
        

        tupleImg=(img,1)
        dataset.append(tupleImg)
        
        
    fileRoute=os.getcwd()
    fileRoute=os.path.join(fileRoute,dataPath,'non-car')
    

    for imgName in os.listdir(fileRoute):
        imgName=os.path.join(fileRoute,imgName)
        img=cv2.imread(imgName)
            
        
        img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        img = cv2.resize(img, (36, 16), interpolation=cv2.INTER_AREA)
        
        
        tupleImg=(img,0)
        dataset.append(tupleImg)
        

    return dataset