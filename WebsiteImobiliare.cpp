#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

class Proprietate{
    protected:
        char tip;
        int pret;
        std::string locatie;
        int suprafata;
    public:
        Proprietate(char tip, int pret, std::string locatie,int suprafata): tip(tip),
            pret(pret), locatie(locatie), suprafata(suprafata){}
        virtual void afisare()=0;
        virtual int calc_st()=0;
        virtual float calc_mp()=0;
        int get_pret(){
            return pret;
        }
        char get_tip(){
            return tip;
        }
        int get_suprafata(){
            return suprafata;
        }
        std::string get_locatie(){
            return locatie;
        }
        virtual int get_dimensiune(){return 0;}
        virtual int get_nr_etaje(){return 0;}
};

class Casa : public Proprietate{
    private:
        int nr_etaje;
    public:
        Casa(char tip,int pret, std::string locatie,int suprafata, int nr_etaje):
            Proprietate(tip,pret, locatie, suprafata), nr_etaje(nr_etaje){}
        void afisare(){
            std::cout<<"Casa "<<pret<<" "<<locatie<<" "<<suprafata<<" "<<nr_etaje<<std::endl;
        }
        int calc_st(){
            return nr_etaje*suprafata;
        }
        float calc_mp(){
            float x;
            x=pret*1.0;
            x=x/calc_st()*1.00;
            return x;
        }
        int get_nr_etaje(){
            return nr_etaje;
        }
        
};

class Apartament: public Proprietate{
    private:
        int dimensiune;
    public:
        Apartament(char tip, int pret, std::string locatie,int suprafata, int dim):
             Proprietate(tip, pret, locatie, suprafata), dimensiune(dim){}
        void afisare(){
            std::cout<<"Apartament "<<pret<<" "<<locatie<<" "<<suprafata<<" "<<dimensiune<<std::endl;
        }
        int calc_st(){
            return dimensiune+suprafata;
        }
        float calc_mp(){
            float x;
            x=pret*1.0;
            x=x/calc_st()*1.00;
            return x;
        }
        int get_dimensiune(){
            return dimensiune;
        }
};

bool metoda(Proprietate *p1, Proprietate *p2){
    if(p1->calc_mp()!=p2->calc_mp())
        return p1->calc_mp()<p2->calc_mp();
    else
        return p1->get_pret()<p2->get_pret();
}

int main(){
    int n,test,temp_p,temp_sup,temp_nre,temp_dim,i;
    std::string temp_l;
    char s;
    std::cin>>n;
    std::vector <Proprietate*> vec;
    for(i=0;i<n;i++){
        std::cin>>s>>temp_p>>temp_l>>temp_sup;
        //std::cout<<s<<temp_p<<temp_l<<temp_sup<<std::endl;
        if(s=='a'){
            std::cin>>temp_dim;
            vec.push_back(new Apartament(s,temp_p,temp_l,temp_sup,temp_dim));
        }
        else{
            std::cin>>temp_nre;
            vec.push_back(new Casa(s,temp_p,temp_l,temp_sup,temp_nre));
        }
    }
    std::cin>>test;
    switch(test){
        case 1:{
           for(i=0;i<n;i++)
            vec[i]->afisare();
           break;    
        }
        case 2:{
            for(i=0;i<n;i++){
                std::cout<<vec[i]->calc_st()<<std::endl;
            }
            break;
        }
        case 3:{
            for(i=0;i<n;i++){
                float x=0.0;
                x=(vec[i]->get_pret()*1.0)/vec[i]->calc_st();
                std::cout<<std::fixed<<std::setprecision(2)<<x<<std::endl;
            }
            break;
        }
        case 4:{
            std::sort (vec.begin(), vec.end(), metoda);
            for(i=0;i<n;i++){
                float x=0.0;
                vec[i]->afisare();
                x=vec[i]->calc_mp();
                std::cout<<std::fixed<<std::setprecision(2)<<x<<std::endl;
            }
            break;
        }
        case 5:{
            int x;
            std::cin>>s>>temp_p>>temp_l>>temp_sup>>x;
            for(i=0;i<n;i++){
                int ok=1;
                if(vec[i]->get_tip()==s && s=='a'){
                    if(temp_p!=0)
                        if(vec[i]->get_pret()<temp_p)
                            ok=0;
                    if(vec[i]->get_locatie()!=temp_l)
                        ok=0;
                    if(temp_sup!=0)
                        if(vec[i]->get_suprafata()<temp_sup)
                            ok=0;
                    if(x!=0)
                        if(vec[i]->get_dimensiune()<x)
                            ok=0;
                    if(ok==1)
                        vec[i]->afisare();
                }
               if(s=='c' && vec[i]->get_tip()==s){
                        //std::cout<<s<<temp_p<<temp_l<<temp_sup<<std::endl;
                        ok=1;
                        //std::cout<<ok<<" 1"<<std::endl;
                        if(temp_p!=0)
                            if(vec[i]->get_pret()<temp_p)
                                ok=0;
                        //std::cout<<"2. "<<ok<<std::endl;
                        if(temp_l!="0")
                        if(vec[i]->get_locatie()!=temp_l)
                            ok=0;
                        //std::cout<<"3."<<ok<<std::endl;
                        if(temp_sup!=0)
                            if(vec[i]->get_suprafata()<temp_sup)
                                ok=0;
                        //std::cout<<"4. "<<ok<<std::endl;
                        if(x!=0)
                            if(vec[i]->get_nr_etaje()<x)
                                ok=0;
                        if(ok==1){
                            //std::cout<<"hello"<<std::endl;
                            vec[i]->afisare();
                        }
                    }
                
            }
            break;
        }
    }
}
