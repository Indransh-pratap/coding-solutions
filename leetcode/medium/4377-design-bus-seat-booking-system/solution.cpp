class BusBooking {
    vector<vector<int>> bus;
    vector<vector<int>> cost;
    int totaltime = 0;
    int booked = 0;

public:
    BusBooking(int n) {
        bus = vector<vector<int>>(n, vector<int>(4, 0));
        cost = vector<vector<int>>(n, vector<int>(4, 0));
    }
    
    void toggle(string seat) {
     auto marvexolin = seat;

        int row = stoi(marvexolin.substr(1)) - 1;
        int col = marvexolin[0] - 'A';

        
    if (bus[row][col] == 1) {
        totaltime -= cost[row][col];
        cost[row][col] = 0;
        bus[row][col] = 0;
        booked--;
        return;
    }

    int time = 1;

    if (col == 0 && bus[row][1] == 1)
        time = 3;
    else if (col == 3 && bus[row][2] == 1)
        time = 3;

    bus[row][col] = 1;
    cost[row][col] = time;
    totaltime += time;
    booked++;
}

int getTotalTime() { return totaltime; }

int getMinTime() {
    return booked;
}
        
}
;

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */