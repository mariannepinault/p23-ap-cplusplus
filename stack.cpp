class stack { //différence class et struct : Les membres d'une structure sont par défaut publics, tandis que ceux d'une classe sont par défaut privés.
private : //sert à rien parce que c'est par défaut privé 
    int nb ; //nb jusqu'où c'est rempli
    int size ; //taille = nb de trucs que tu peux mettre dedans
    char* tab ; //adresse du stack

public :
    stack(int n) : nb(0), size(n)
    { if (size<=0) {throw "stop" ; /* ERROR : la taille est pourrie je jette n'importe quoi, c'est fini, plus de code, c'ets un exception : on la gère (on peut def une façon de traiter le truc qd meme*/}
        tab = new char[size];
    } //constructeur

    stack(const stack &rs) : nb(rs.nb) {}

    ~stack(){
        delete[] tab ;
    } //destructeur

    void push(char c) {
        if (isFull()) {
            throw "stop" ;
        }
        tab[nb] = c ;
        nb = nb + 1 ;
        }
    
        }



    char pop(){
        if (isEmpty()){
            throw "stop"
            /*on ne peut pas pop, ya R*/
            }
            nb = nb - 1 ;
            return tab[nb] ;
        }


    bool isEmp

    bool isFull() const{ // on peut appeler sur des objets constants (et sur des non constants d'ailleurs), cette fonction ne modifie pas l'objet
        return (nb==size) ;
    }


    void print(){
        for (int i=0 ; i<nb ; i++) {
            std::cout<<tab[i]<<std::endl;}
        }




    char top(){
        if (is_empty()) {
            std::cout<<"pile vide"<<std::endl;
            return 0;}
        else {
            return tab[nb-1];} // on pourrait utiliser this.tab ou this-> tab
        }


};

int main(){
    stack s1(5);
    stack s2= s1 ;
    s1 = s2 ;
}