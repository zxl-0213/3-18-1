#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//��ӡ����
void print(int* a, int n);
//ֱ�Ӳ�������
void  InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);


//ֱ��ѡ������
void SelectSort(int* a, int n,int begin,int end);

//������
void HeapSort(int* a, int n);

//ð������
void ButtleSort(int* a,int n);

//��������()
void  QuickMethod(int* a, int begin,int end);


//�鲢����
void MergeSort(int* a, int n);


//��������
void CountSort(int* a, int n);