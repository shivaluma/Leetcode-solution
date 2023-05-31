class ParkingSystem {
public:
    vector<int> slots;
    ParkingSystem(int big, int medium, int small) {
        slots.push_back(0);
        slots.push_back(big);
        slots.push_back(medium);
        slots.push_back(small);
    }
    
    bool addCar(int carType) {
        if (slots[carType] == 0) {
            return false;
        }

        slots[carType]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */