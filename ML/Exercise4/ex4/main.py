#Group
#Person 1: Leul Shiferaw
#Person 2: Biruk Wossene Amare

#Kmeans clustering for image dataset
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import sys

#mean function
def mean(x):
    res=x[0]
    for i in range(1,len(x)):
        res+=x[i]
    return res/len(x)

#input k
k=int(input("K: "))

#read data from file
f=open('mfeat-pix.txt','r')
read_data=f.read()
f.close()

#put data in training dataset
tr_ds=[] #training dataset
for i in read_data:
    if i>='0' and i<='9':
        tr_ds.append(int(i))

#initialize data
num=0
init=np.array(tr_ds).reshape(2000,-1)[num*200:(num+1)*200]

#display image data
"""
for i in range(len(init)):
    plt.imshow(init[i].reshape(16,15),cmap='binary')
    plt.show()
    input(":")
"""

j=0
prev=[] #prev is just the first randomly clustered data
end=True
while end:
    temp=[]
    for i in range(int(200/k)): #you need 200/k elements in one cluster to group into k
        if j >= 200:
            end=False
            break
        temp.append(init[j])
        j=j+1
    if end:
        prev.append(temp)

itr=0 #Current iteration
while True:
    itr+=1
    print(itr)

    #initialized 2-d array for storing new cluster
    temp=[]
    for i in range(len(prev)):
        temp.append([])

    #calc list of means
    set_mean=[]
    for i in range(len(prev)):
        set_mean.append(prev[i])

    #for all test data
    for i in range(len(init)):
        ind=0
        small=np.linalg.norm(init[i]-set_mean[0]) 
        for j in range(1,len(set_mean)):    #go through all the mean and determine the one with the smallest |x-mean| value
            curr_sm=np.linalg.norm(init[i]-set_mean[j])
            if curr_sm<small:
                small=curr_sm
                ind=j
        temp[ind].append(init[i]) #append smallest to temp
    
    #remove empty lists and store in curr
    curr=[]
    for i in temp:
        if np.array_equal(i,np.array([]))==False:
            curr.append(i)
    
    #check if prev and curr are equal
    equal=(len(prev)==len(curr)) #start calc if they have same length
    if len(prev)==len(curr):
        for i in range(len(prev)):
            if not np.array_equal(prev[i],curr[i]):
               equal=False
               break
    if equal:
        break
    prev=curr.copy()

print("New K: ", len(curr))
#visualize data
for i in range(len(curr)):
    temp=mean(curr[i]) #calculate the centroids
    plt.imshow(temp.reshape(16,15),cmap='binary')
    plt.show()
    input(":")

