import dataset
import adaboost
import utils
import detection
import matplotlib.pyplot as plt

import SOTA

'''
#Part 1: Implement loadImages function in dataset.py and test the following code.
print('Loading images')
trainData = dataset.loadImages('data/train')
print(f'The number of training samples loaded: {len(trainData)}')
testData = dataset.loadImages('data/test')
print(f'The number of test samples loaded: {len(testData)}')
print('Show the first and last images of training dataset')
fig, ax = plt.subplots(1, 2)
ax[0].axis('off')
ax[0].set_title('Car')
#ax[0].imshow(trainData[1][0], cmap='gray')
ax[1].axis('off')
ax[1].set_title('Non car')
#ax[1].imshow(trainData[-1][0], cmap='gray')
plt.show()
'''
# Part 2: Implement selectBest function in adaboost.py and test the following code.
# Part 3: Modify difference values at parameter T of the Adaboost algorithm.
# And find better results. Please test value 1~10 at least.
'''
print('Start training your classifier')
clf = adaboost.Adaboost(T=4)
clf.train(trainData)

clf.save('clf_300_1_10')
'''
trainData = dataset.loadImages('data/train')
testData = dataset.loadImages('data/test')

clf = adaboost.Adaboost.load('clf_300_1_10_SOTA')

print('\nEvaluate your classifier with training dataset')
utils.evaluate(clf, trainData)

print('\nEvaluate your classifier with test dataset')
utils.evaluate(clf, testData)



# Part 4: Implement detect function in detection.py and test the following code.
print('\nUse your classifier with video.gif to get the predictions (one .txt and one .png)')
detection.detect('data/detect', clf)

#Part 6:SOTA method
'''
print('Start training your SOTA classifier')
clf = SOTA.Adaboost(T=10)
clf.train(trainData)

clf.save('clf_300_1_10_SOTA')

clf = SOTA.Adaboost.load('clf_300_1_10')


print('\nEvaluate your classifier with training dataset')
utils.evaluate(clf, trainData)

print('\nEvaluate your classifier with test dataset')
utils.evaluate(clf, testData)

'''