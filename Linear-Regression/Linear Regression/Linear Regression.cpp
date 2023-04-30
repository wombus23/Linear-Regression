#include <iostream>
#include <vector>

using namespace std;

class LinearRegression {
private:
    vector<double> X; // Input data
    vector<double> Y; // Output data
    double slope; // The slope of the line
    double intercept; // The y-intercept of the line

public:
    LinearRegression(vector<double> x, vector<double> y) {
        X = x;
        Y = y;
    }

    // Function to calculate the slope of the line
    double getSlope() {
        return slope;
    }

    // Function to calculate the y-intercept of the line
    double getIntercept() {
        return intercept;
    }

    // Function to optimize the slope and y-intercept using gradient descent
    void optimize(double learning_rate, int num_iterations) {
        double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;
        for (int i = 0; i < X.size(); i++) {
            sum_x += X[i];
            sum_y += Y[i];
            sum_xy += X[i] * Y[i];
            sum_x2 += X[i] * X[i];
        }

        // Initialize the slope and y-intercept
        slope = 0.0;
        intercept = 0.0;

        // Run gradient descent for the specified number of iterations
        for (int i = 0; i < num_iterations; i++) {
            // Calculate the predicted values using the current slope and y-intercept
            vector<double> y_pred(X.size());
            for (int j = 0; j < X.size(); j++) {
                y_pred[j] = slope * X[j] + intercept;
            }

            // Calculate the gradients of the slope and y-intercept
            double grad_slope = 0.0, grad_intercept = 0.0;
            for (int j = 0; j < X.size(); j++) {
                grad_slope += (y_pred[j] - Y[j]) * X[j];
                grad_intercept += y_pred[j] - Y[j];
            }

            // Update the slope and y-intercept
            slope -= learning_rate * grad_slope / X.size();
            intercept -= learning_rate * grad_intercept / X.size();
        }
    }
};

int main() {
    // Sample data
    vector<double> x = { 1, 2, 3, 4, 5 };
    vector<double> y = { 3, 5, 7, 9, 11 };

    // Create a linear regression object
    LinearRegression lr(x, y);

    // Optimize the slope and y-intercept using gradient descent
    double learning_rate = 0.01;
    int num_iterations = 1000;
    lr.optimize(learning_rate, num_iterations);

    // Print the optimized slope and y-intercept of the line
    cout << "Slope: " << lr.getSlope() << endl;
    cout << "Y-Intercept: " << lr.getIntercept() << endl;

    return 0;
}
