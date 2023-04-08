import matplotlib.pyplot as plt
import math
import numpy as np

with open("bubbleSort.txt","r") as f:
    lines = f.readlines()
    ybubbleSort = []
    xbubbleSort = []
    cont = 0
    for i in lines:
        ybubbleSort.append(float(i))
        xbubbleSort.append(cont)
        cont+=1


with open("insertionSort.txt","r") as f:
    lines = f.readlines()
    yinsertionSort = []
    xinsertionSort = []
    cont = 0
    for i in lines:
        yinsertionSort.append(float(i))
        xinsertionSort.append(cont)
        cont+=1
with open("mergeSort.txt","r") as f:
    lines = f.readlines()
    ymergeSort = []
    xmergeSort = []
    cont = 0
    for i in lines:
        ymergeSort.append(float(i))
        xmergeSort.append(cont)
        cont+=1
with open("quickSort.txt","r") as f:
    lines = f.readlines()
    yquickSort = []
    xquickSort = []
    cont = 0
    for i in lines:
        yquickSort.append(float(i))
        xquickSort.append(cont)
        cont+=1
with open("heapSort.txt","r") as f:
    lines = f.readlines()
    yheapSort = []
    xheapSort = []
    cont = 0
    for i in lines:
        yheapSort.append(float(i))
        xheapSort.append(cont)
        cont+=1
with open("buscaSequencial.txt","r") as f:
    lines = f.readlines()
    ybuscaSequencial = []
    xbuscaSequencial = []
    cont = 0
    for i in lines:
        ybuscaSequencial.append(float(i))
        xbuscaSequencial.append(cont)
        cont+=1
with open("buscaBinaria.txt","r") as f:
    lines = f.readlines()
    ybuscaBinaria = []
    xbuscaBinaria = []
    cont = 0
    for i in lines:
        ybuscaBinaria.append(float(i))
        xbuscaBinaria.append(cont)
        cont+=1
plt.xticks()
plt.ylim(0,3000)
plt.plot(xbubbleSort, ybubbleSort, label="bubbleSort", linewidth=1.5)
plt.plot(xinsertionSort, yinsertionSort, label="insertionSort", linewidth=1.5)
plt.plot(xmergeSort, ymergeSort, label="mergeSort", linewidth=1.5)
plt.plot(xquickSort, yquickSort, label="quickSort", linewidth=1.5)
plt.plot(xheapSort, yheapSort, label="heapSort", linewidth=1.5)
plt.plot(xbuscaSequencial, ybuscaSequencial, label="buscaSequencial",linewidth=1.5)
plt.plot(xbuscaBinaria, ybuscaBinaria, label="buscaBinaria",linewidth=1.5)
plt.xlabel("Elementos")
plt.ylabel("Tempo(uSec)")
plt.legend(loc="upper left")
plt.savefig("complexityComparison.png")
plt.close()
f.close()
plt.plot(xmergeSort, ymergeSort, label="mergeSort", linewidth=1.5)
plt.plot(xquickSort, yquickSort, label="quickSort", linewidth=1.5)
plt.plot(xheapSort, yheapSort, label="heapSort", linewidth=1.5)
plt.plot(xbuscaSequencial, ybuscaSequencial, label="buscaSequencial",linewidth=1.5)
plt.plot(xbuscaBinaria, ybuscaBinaria, label="buscaBinaria",linewidth=1.5)
plt.xlabel("Elementos")
plt.ylabel("Tempo(uSec)")
plt.legend(loc="upper left")
plt.savefig("goodComplexityComparison.png")
plt.close()
f.close()
plt.plot(xbuscaSequencial, ybuscaSequencial, label="buscaSequencial",linewidth=1.5)
plt.plot(xbuscaBinaria, ybuscaBinaria, label="buscaBinaria",linewidth=1.5)
plt.xlabel("Elementos")
plt.ylabel("Tempo(uSec)")
plt.legend(loc="upper left")
plt.savefig("bestComplexityComparison.png")
plt.close()
f.close()

