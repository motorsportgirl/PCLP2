

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

int capacitate(std::string nume){
    if(nume=="single")
        return 1;
    if(nume=="twin" || nume=="double")
        return 2;
    if(nume=="triple")
        return 3;
    return 0;
}


class Hotel{
    private:
        std::string tip;
        int nr, pers_c,pret;
    public:
        Hotel(int nr, std::string tip, int pers_c, int pret): nr(nr), tip(tip), pers_c(pers_c), pret(pret){}
        int get_capacitate(){
            return capacitate(tip);
        }
        int get_pers_c(){
            return pers_c;
        }
        int get_pret(){
            return pret;
        }
        void afisare(){
            std::cout<<nr<<" "<<tip<<" "<<pers_c<<" "<<pret<<std::endl;
        }
        
};
bool comparare(Hotel *h1, Hotel *h2){
    if(h1->get_capacitate()==h2->get_capacitate()){
        if(h1->get_pret()<h2->get_pret())
            return true;
        else
            return false;
    }
    else
        if(h1->get_capacitate()<h2->get_capacitate())
            return true;
        else
            return false;
}
int main(){
    int comanda;
    std::string temp_t;
    std::vector <Hotel*> vec;
    int temp_pers=-1, temp_pret,nr;
    do{
        std::cin>>comanda;
        switch(comanda){
            case 1:{
                std::cin>>nr>>temp_t>>temp_pers>>temp_pret;
                vec.push_back(new Hotel(nr,temp_t,temp_pers,temp_pret));
                break;
            }
            case 2: {
                for(int i=0;i<vec.size();i++)
                    vec[i]->afisare();
                break;
            }
            case 3: {
                int k=0,i;
                for(i=0;i<vec.size();i++){
                    if(vec[i]->get_pers_c()==0)
                        k++;
                }
                //std::cout<<i<<std::endl;
                std::cout<<std::fixed<<std::setprecision(2)<<1.0*(i-k)/i*100<<std::endl;
                break;
            }
            case 4:{
                int k=0,i;
                for(i=0;i<vec.size();i++){
                    if(vec[i]->get_pers_c()==0)
                        k+=vec[i]->get_capacitate();
                }
                std::cout<<k<<std::endl;
                break;
            }
            case 5 :{
                std::sort(vec.begin(), vec.end(), comparare);
                for(int i=0;i<vec.size();i++){
                    vec[i]->afisare();
                }
                break;
            }
        }
    }while(comanda!=-1);
}
