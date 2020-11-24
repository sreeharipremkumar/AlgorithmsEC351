#importing the necessary libraries
import glob	    
import cv2
import os
import shutil
import time

#Quick sort Algorithm to sort the images based on size
def QuickSort(arr,left,right):
    i = left
    j = right
    piv = arr[left + (right - left) // 2][1] 
    while i <= j:
        while arr[i][1] < piv: i += 1
        while arr[j][1] > piv: j -= 1
        if i <= j: 
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
    if left < j:
        QuickSort(arr, left, j)
    if i < right: 
        QuickSort(arr, i, right)
    return arr

#Sort Function
def Sort(arr,n):
    begin = time.perf_counter()
    arr1 = QuickSort(arr,0,n-1)
    end = time.perf_counter()

    print(f"\nTotal runtime of the program is {(end - begin)*1000000000} ns")

    if os.path.exists(dir+'/Sorted'):
        shutil.rmtree(dir+'/Sorted')
    os.makedirs(dir+'/Sorted')

    for i in range(n):
        shutil.copy(dir+'/Images/'+arr1[i][0],dir+'/Sorted')
        os.rename(dir+'/Sorted/'+arr1[i][0],dir+'/Sorted/{0} '.format(i)+arr1[i][0])
    return

#Binary search function
def BinarySearch(arr,img_size):

    h = n-1
    l = 0
    m = 0
    arr = QuickSort(arr,0,n-1)
    begin = time.perf_counter()
    while l<=h:
        
        m = int((l+h)/2)

        if arr[m][1] < img_size:
            l = m + 1
        elif arr[m][1] > img_size:
            h = m - 1
        else:
            end =time.perf_counter()
            print(f"\nTotal runtime of the program is {(end - begin)*1000000000} ns")
            return m,arr
    end =time.perf_counter()
    print(f"\nTotal runtime of the program is {(end - begin)*1000000000} ns")
    return -1,arr

#Linear search function
def LinearSearch(arr,img_size,img):
    begin = time.perf_counter()

    for i in range(n):
        if(arr[i][1]==img_size):
            img2 = cv2.imread(dir+"/Images/"+arr[i][0])

            if(img == img2).all():
                end =time.perf_counter()
                print(f"\nTotal runtime of the program is {(end - begin)*1000000000} ns")
                return i
            
    end = time.perf_counter()

    print(f"\nTotal runtime of the program is {(end - begin)*1000000000} ns")
    return -1


#Search Function
def Search(arr,dir):

    files=glob.glob(dir+"/Finder/*.jpg")

    if not files:
        print("No images in the finder folder")
        return
    img = cv2.imread(files[0])
    img_size = img.size
    out = 0

    sw = int(input("\n\n1) Linear. \n2) Binary\nEnter : "))
    if sw == 1 :
        out = LinearSearch(arr,img_size,img)
    elif sw == 2 :
        out,arr = BinarySearch(arr,img_size)
    else:
        print("\n\nInvalid Choice")
        return

    if out == -1:
        print("\nImage Not Found")
    else:

        img2 = cv2.imread(dir+"/Images/"+arr[out][0])

        img = cv2.resize(img, (960, 960))
        img2 = cv2.resize(img2, (960, 960))
        cv2.imshow("Image 1",img)
        cv2.imshow("Image 2",img2)
        cv2.waitKey(0)
    
    return

#Read the images from Images folder
def Read(dir):

    files = glob.glob(dir+'/Images/*.jpg')
    n = len(files)
    x_data =[]

    for i in files:
        img = cv2.imread(i)
        x_data.append([os.path.basename(i),img.size])

    return x_data,n

#Main Program
dir = os.path.dirname(__file__)
x_data,n = Read(dir)
print(x_data)
sw = int(input("\n\n1) Sorting. \n2) Searching\nEnter : "))

if sw == 1 :
    Sort(x_data,n)
    print("\nSorting Completed check the Sorted Folder")
elif sw ==2 :
    Search(x_data,dir)
else:
    print("\n\nInvalid Choice")
