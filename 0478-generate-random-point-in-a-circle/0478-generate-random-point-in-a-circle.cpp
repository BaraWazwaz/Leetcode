class Solution {
    mt19937 engine;
    uniform_real_distribution<double> dist;
    double radius, x_center, y_center;

public:
    Solution(double radius, double x_center, double y_center) :
        engine(std::chrono::system_clock::now().time_since_epoch().count()),
        radius(radius),
        dist(-1.0, 1.0),
        x_center(x_center),
        y_center(y_center)
    {}
    
    vector<double> randPoint() {
        double x, y;
        do x = dist(engine), y = dist(engine);
        while (x * x + y * y > 1);
        return { x_center + x * radius, y_center + y * radius };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */