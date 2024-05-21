#include <iostream>
#include <string>
#include <vector>

class Card_calatorie{
    protected:
        char c;
        int id;
        int val;
        int moment=0;
    public:
        Card_calatorie(int id, char c, int val): id(id), c(c), val(val){}
        virtual void display()=0;
        virtual void validare(int x)=0;
        void set_moment(int x){
            this->moment=x;
        }
        char get_c(){
            return c;
        }
        int get_moment(){
            return this->moment;
        }
        int get_id(){
            return this->id;
        }
        int get_val(){
            return this->val;
        }
        void incarcare(int x){
            val=val+x;
        }
        void scadere(int x){
            val=val-x;
        }
};

class Metrou: public Card_calatorie{
    private:
        int nr_c;
    public:
        Metrou(int id,char c,int nr_c): Card_calatorie(id,c,nr_c){}
        void display(){
            std::cout<<id<<" "<<c<<" "<<val<<" "<<get_moment()<<std::endl;
        }
        void validare(int x){
            if(x-get_moment()<90 && get_moment()!=0)
                //set_moment(x);
                return;
            else{
                if(get_val()>=1){
                    scadere(1);
                    set_moment(x);
                }
                else{
                    std::cout<<"Numar calatorii insuficient"<<std::endl;
                } 
            }
        }
};

class Autobuz: public Card_calatorie{
    private:
    int sold;
    public:
         Autobuz(int id,char c,int sold): Card_calatorie(id,c,sold){}
         void display(){
             std::cout<<id<<" "<<c<<" "<<val<<" "<<get_moment()<<std::endl;
         }
         void validare(int x){
            if(x-get_moment()<90 && get_moment()!=0)
                //set_moment(x);
                return;
            else{
                if(get_val()>=3){
                    scadere(3);
                    set_moment(x);
                }
                else{
                    std::cout<<"Sold insuficient"<<std::endl;
                } 
            }
         }
};

int main(){
    std::vector <Card_calatorie*> vec;
    int n,temp_id,val_int;
    char caracter;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>caracter>>temp_id>>val_int;
        //std::cout<<temp_id<<" "<<caracter<<" "<<val_int;
        if(caracter=='a')
            vec.push_back(new Autobuz(temp_id,caracter,val_int));
        else
            vec.push_back(new Metrou(temp_id,caracter,val_int));
    }
    int test;
    do{
        std::cin>>test;
        if(test==1){
            for(int i=0;i<vec.size();i++)
                vec[i]->display();
        }
        if(test==2){
            std::cin>>temp_id>>val_int;
            for(int i=0;i<vec.size();i++){
                if(temp_id==vec[i]->get_id()){
                    vec[i]->incarcare(val_int);
                }
            }
        }
        if(test==3){
            int mom;
            std::cin>>temp_id>>mom;
             for(int i=0;i<vec.size();i++){
                if(temp_id==vec[i]->get_id()){
                    vec[i]->validare(mom);
                }
            }
        }
        if(test==4){
            char c1,c2;
            int t_id,k1,k2;
            std::cin>>temp_id>>t_id>>val_int;
            for(int i=0;i<vec.size();i++){
                if(temp_id==vec[i]->get_id()){
                    c1=vec[i]->get_c();
                    k1=i;
                }
                if(t_id==vec[i]->get_id()){
                    c2=vec[i]->get_c();
                    k2=i;
                }
            }
            if(c1==c2){
                    if(vec[k1]->get_val()<val_int)
                        std::cout<<"Transfer nereusit"<<std::endl;
                    else{
                       vec[k1]->scadere(val_int);
                       vec[k2]->incarcare(val_int);
                    }
                }
                else
                    std::cout<<"Transfer nereusit"<<std::endl;
        }
    }while(test!=5);
    
}
