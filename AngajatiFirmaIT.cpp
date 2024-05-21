#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Angajat{
    protected:
        std::string nume, functie;
        float salariu_baza, procent_taxe_salariu;
    public:
        Angajat(std::string nume, std::string functie, float salariu_baza): nume(nume), functie(functie), salariu_baza(salariu_baza){}
        virtual float get_salariu_net(){
            return 0;
        }
        float get_salariu_baza(){
            return salariu_baza;
        }
        std::string get_nume(){
            return nume;
        }
        std::string get_functie(){
            return functie;
        }
        float marire_salariu(int x){
            return 0;
        }
        virtual float get_salariu_brut(){
            return 0;
        }
        virtual ~Angajat(){
            std::cout<<"Destructor Angajat"<<std::endl;
        }
};

class Analist : public Angajat{
    public:
     Analist(std::string nume, std::string functie, float salariu_baza): Angajat(nume, functie, salariu_baza){}
     float get_salariu_brut(){
        return get_salariu_baza();
    }
    float get_salariu_net(){
            return get_salariu_baza()-get_salariu_baza()*0.4;
    }
    float marire_salariu(int x){
        return get_salariu_baza();
        //+get_salariu_baza()*x;
    }
    ~Analist(){
        std::cout<<"Destructor Analist"<<std::endl;
    }
};

class Programator : public Analist{
    protected:
        float procent_deducere_salariu_it;
    public:
        Programator(std::string nume, std::string functie, float salariu_baza): Analist(nume, functie, salariu_baza){}
        float get_salariu_brut(){
            return get_salariu_baza();
        }
        float get_salariu_net(){
            return get_salariu_baza()-get_salariu_baza()*0.3;
        }
        float marire_salariu(int x){
            return get_salariu_baza();
            //+get_salariu_baza()*x;
        }
        ~Programator(){
            std::cout<<"Destructor Programator"<<std::endl;
        }
    
};

class LiderEchipaProgramare : public Programator {
    protected:
        float bonus_vechime_functie;
        int vechime_functie;
    public:
        LiderEchipaProgramare(std::string nume, std::string functie, float salariu_baza, int vechime_functie): 
            Programator(nume, functie, salariu_baza), vechime_functie(vechime_functie){}
        float get_salariu_brut(){
            return (get_salariu_baza()+vechime_functie*500);
        }
        float get_salariu_net(){
            return get_salariu_brut()-((get_salariu_baza()+vechime_functie*500)*0.3);
        }
        float marire_salariu(int x){
            return get_salariu_baza();
            //+get_salariu_baza()*x;
        }
        ~LiderEchipaProgramare(){
            std::cout<<"Destructor LiderEchipaProgramare"<<std::endl;
            
        }
};

class FirmaProgramare{
    private:
     std::vector <Angajat*> vec;
    public:
        void vec_add( Angajat* angajat){
            vec.push_back(angajat);
        }
        void afisare_angajati(){
            for(int i=0;i<vec.size();i++){
                std::cout<<vec[i]->get_nume()<<std::endl;
                std::cout<<vec[i]->get_functie()<<std::endl;
            }
        }
        void calcul_salariu(){
            for(int i=0;i<vec.size();i++){
                std::cout<<vec[i]->get_nume()<<std::endl;
                std::cout<<"Salariu brut: "<<vec[i]->get_salariu_brut()<<std::endl;
                std::cout<<"Salariu Net: "<<vec[i]->get_salariu_net()<<std::endl;
            }
        }
        void calcul_marire(){
            std::string rol;
            int marire;
            std::cin>>rol>>marire;
            //std::cout<<marire<<std::endl;
            for(int i=0;i<vec.size();i++){
                if(vec[i]->get_functie()==rol){
                    std::cout<<vec[i]->get_nume()<<std::endl;
                    std::cout<<"Salariu de baza vechi: "<<vec[i]->get_salariu_baza()<<std::endl;
                    std::cout<<"Salariu de baza nou: "<<vec[i]->get_salariu_baza()+vec[i]->get_salariu_baza()*marire/100<<std::endl;
                }
            }
        }
        void promovare(std::string nume, std::string rol){
            int i;
            for(i=0;i<vec.size();i++){
                if(vec[i]->get_nume()==nume){
                    //std::cout<<"ok"<<std::endl;
                    delete vec[i];
                    break;
                }
            }
            if(rol=="Programator")
                vec[i]= new Programator(nume,"Programator",0);
            else
                if(rol=="LiderEchipaProgramare")
                    vec[i]= new LiderEchipaProgramare(nume,rol,0,0);
        }
        void destructor(){
            for(int i=0;i<vec.size();i++){
                delete vec[i];
            }
        }
};

int main(){
    int n;
    FirmaProgramare angajat;
    std::string temp_n,rol;
    float temp_sb;
    int temp_v, i,test;
    std::cin>>n;
    for(i=0;i<n;i++){
        std::getline(std::cin>>std::ws, temp_n);
        std::cin>>rol>>temp_sb;
        if(rol=="LiderEchipaProgramare"){
            std::cin>>temp_v;
            angajat.vec_add( new LiderEchipaProgramare(temp_n,rol,temp_sb,temp_v));
        }
        if(rol=="Programator"){
            angajat.vec_add(new Programator(temp_n,rol,temp_sb));
        }
        if(rol=="Analist"){
            angajat.vec_add(new Analist(temp_n,rol,temp_sb));
        }
    }
    std::cin>>test;
    switch(test){
        case 1:{
            angajat.afisare_angajati();
            break;
        }
        case 2: {
            angajat.calcul_salariu();
            break;
        }
        case 3: {
            for(i=0;i<3;i++){
                angajat.calcul_marire();
            }
            break;
        }
        case 4 : {
            std::getline(std::cin>>std::ws, temp_n);
            std::cin>>rol;
            //std::cout<<temp_n<<" "<<rol<<std::endl;
            //angajat.destructor();
            angajat.promovare(temp_n,rol);
            angajat.afisare_angajati();
            break;
        }
    }
    
}
