#pragma once
#include "CNode.h"
#include <iostream>
template <typename T>
class CDblLinkedList{
    private:
        CNode<T>*head=nullptr,*current=nullptr;
    public:
        CDblLinkedList();
        void Insert(T p_data);
        void Next();
        T GetCurr(void){return(current->GetData());};
        ~CDblLinkedList();
};

template<typename T>
CDblLinkedList<T>::CDblLinkedList(){
}

template<typename T>
void CDblLinkedList<T>::Insert(T p_data){
    CNode<T> * dummy=new CNode<T>(p_data);
    if(!head){
        head=dummy;
        head->SetNext(head);
        head->SetPrev(head);
        current=head;
    }else{
        dummy->SetPrev(head->GetPrev());
        dummy->SetNext(head);
        head->GetPrev()->SetNext(dummy);
        head->SetPrev(dummy);
    }
}
template<typename T>
void CDblLinkedList<T>::Next(){
    current=current->GetNext();
}

template<typename T>
CDblLinkedList<T>::~CDblLinkedList(){
    if(head){
        head->GetPrev()->SetNext(nullptr);
        CNode<T>* dummy=nullptr;
        while(head){
            dummy=head;
            head=head->GetNext();
            std::cout<<'a'<<dummy->GetData()<<std::endl;
            delete dummy;
            dummy=nullptr;
        }
        head=nullptr;
        current=nullptr;
    }
}

