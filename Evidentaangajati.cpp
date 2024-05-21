#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Angajat{
private:
    std::string nume;
    std::string departament;
public:
    Angajat(std::string nume, std::string departament):nume(nume), departament(departament){}
    virtual void afisare() = 0;
    virtual float rentabilitate_angajat() = 0;
    virtual int salariu_brut()=0;
    std::string get_nume(){
        return nume;
    }
    std::string get_departament(){
        return departament;
    }
};

class Salariat : public Angajat{
    private:
        int norma, vechime;
        float salariu_net;
    public:
        Salariat(std::string nume,std::string dep,int norma, int vechime, float salariu): Angajat(nume,dep), norma(norma), 
        vechime(vechime), salariu_net(salariu){}
        void afisare(){
            std::cout<<get_nume()<<" "<<norma<<" "<<vechime<<" "<<salariu_net<<std::endl;
        }
        int salariu_brut(){
            float x;
            if(get_departament()!="IT")
                return salariu_net*12/0.55;
            else
                return salariu_net*12/0.65;
            //return float(x);
        }
        float rentabilitate_angajat(){
            float x;
            x=norma*(250-20-vechime/3);
            x=x/salariu_brut();
            return x;
        }
};

class Colaborator: public Angajat{
    private:
        float onorariu, nr_prestari_anuale;
    public:
        Colaborator(std::string nume,std::string dep, float onorariu, float nr_prestari_anuale): Angajat(nume,dep), 
        onorariu(onorariu), nr_prestari_anuale(nr_prestari_anuale){}
        void afisare(){
            std::cout<<get_nume()<<" "<<onorariu<<" "<<nr_prestari_anuale<<std::endl;
        }
        int salariu_brut(){
            float x;
            if(get_departament()!="IT")
                x=(nr_prestari_anuale*onorariu)/0.55;
            else
                x=(nr_prestari_anuale*onorariu)/0.65;
            return x;
        }
        float rentabilitate_angajat(){
            return 0;
        }
        
};      
    
int main(){
    int n,i,test;
    std::string tip, n_a, n_d,dep;
    int temp_n,temp_v;
    float salariu, onorariu, prestari;
    std::vector <Angajat*> vec;
    std::cin>>n;
    for(i=0;i<n;i++){
        std::cin>>tip>>n_a>>n_d;
        if(tip=="salariat"){
            std::cin>>temp_n>>temp_v>>salariu;
            vec.push_back(new Salariat(n_a, n_d,temp_n, temp_v,salariu));
        }
        else{
            std::cin>>onorariu>>prestari;
            vec.push_back(new Colaborator(n_a,n_d,onorariu,prestari));
        }
    }
    std::cin>>test;
    switch(test){
        case 1:{
            std::cin>>dep;
            for(i=0;i<n;i++){
                if(vec[i]->get_departament()==dep)
                vec[i]->afisare();
            }
            break;
        }
        case 2:{
            std::cin>>n_a;
            for(i=0;i<n;i++){
                if(vec[i]->get_nume()==n_a)
                    std::cout<<vec[i]->salariu_brut()<<std::endl;
            }
            break;
        }
        case 3:{
            float a,max=-1.00;
            int k;
            for(i=0;i<n;i++){
                    a=vec[i]->rentabilitate_angajat();
                if(a>max){
                    max=a;
                    k=i;
                }
            }
            std::cout<<vec[k]->get_nume()<<std::endl;
            break;
        }
        case 4:{
            std::cin>>n_d;
            float s=0.00;
            int k=0;
            for(i=0;i<n;i++){
                if(vec[i]->get_departament()==n_d){
                    s+=vec[i]->salariu_brut();
                    k++;
                }
            }
            std::cout<<std::fixed<<std::setprecision(2)<<(float)s/k;
            break;
        }
    }
}
