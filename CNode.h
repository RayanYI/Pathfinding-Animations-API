#pragma once
template <typename T>
class CNode{

    private:
        CNode*prev=nullptr;
        T data;
        CNode*next=nullptr;

    public:
        CNode(T p_data,CNode*p_prev=nullptr,CNode*p_next=nullptr);
        void SetNext(CNode*p_next){next=p_next;};
        void SetPrev(CNode*p_prev){prev=p_prev;};
        CNode* GetNext(void)const{return(next);};
        CNode* GetPrev(void)const{return(prev);};
        T GetData(void){return(data);};

};

template <typename T>
CNode<T>::CNode(T p_data,CNode*p_prev,CNode*p_next){
    data=p_data;
    prev=p_prev;
    next=p_next;
}