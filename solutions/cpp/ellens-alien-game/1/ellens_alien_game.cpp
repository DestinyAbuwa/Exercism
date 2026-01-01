namespace targets {
class Alien{
    private: 
    int health;
    
    public:
    int x_coordinate;
    int y_coordinate;
    

    Alien(int x, int y){
        x_coordinate = x;
        y_coordinate = y;
        health = 3;
    }

    int get_health(){
        return health;
    }    

    bool hit(){
        if(health > 0){
            health--;
            return true;
        }

        return false;
    }

    bool is_alive(){
        return health > 0;
    }

    bool teleport(int x_new, int y_new){
        x_coordinate = x_new;
        y_coordinate = y_new;
        return true;
    }

    bool collision_detection(Alien a){
        return x_coordinate == a.x_coordinate && y_coordinate == a.y_coordinate;
    }
};

}  // namespace targets
