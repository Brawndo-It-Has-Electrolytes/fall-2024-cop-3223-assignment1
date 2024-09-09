#include <stdio.h>
#include <math.h>

#define PI 3.14159

double calculate_distance();  // declaration errors when compiling, something about conflicting types and implicit
double calculate_perimeter();//declaration, so trying these?
double calculate_area();
double calculate_width();
double calculate_height();


int main(int argc, char **argv) {

    printf("Calculate all values:\n");

    double distance = calculate_distance();//would not run anything past the main, would just say 0 and stop
    double perimeter = calculate_perimeter();//so im putting these here maybe this works
    double area = calculate_area();
    double width = calculate_width();
    double height = calculate_height();

    //printf("\nFinal Calculations:\n");
    //printf("Distance: %.2lf\n", distance);
    //printf("Perimeter: %.2lf\n", perimeter);
    //printf("Area: %.2lf\n", area);
    //printf("Width: %.2lf\n", width);
    //printf("Height: %.2lf\n", height);

    return 0;
}

double calculate_distance() {
    double x1, y1, x2, y2;
    
    printf("Enter x1 for Point #1: ");
    scanf("%lf", &x1);

    printf("Enter y1 for Point #1: ");
    scanf ("%lf", &y1);
    
    printf("Enter x2 for Point #2: ");
    scanf("%lf", &x2);

    printf("Enter y2 for Point #2: ");
    scanf ("%lf", &y2);
    
    
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    printf("Point #1 entered: x1 = %.2lf; y1 = %.2lf\n", x1, y1);
    printf("Point #2 entered: x2 = %.2lf; y2 = %.2lf\n", x2, y2);
    printf("The distance between the two points is %.2lf\n", distance);
    
    return distance;
}

double calculate_perimeter() {

    double distance = calculate_distance();
    double perimeter = 2 * PI * distance;
    
    printf("The perimeter of the city encompassed by your request is %.2lf\n", perimeter);
    
    return 1.0;  // not very difficult
}

double calculate_area() {

    double distance = calculate_distance();
    double area = PI * pow(distance, 2);
    
    printf("The area of the city encompassed by your request is %.2lf\n", area);
    
    return 3.0;  // had to find the pow 
}

double calculate_width() {

    double x1, y1, x2, y2;
    
    printf("Enter x1 for Point #1: ");
    scanf("%lf", &x1);

    printf("Enter y1 for Point #1: ");
    scanf ("%lf", &y1);
    
    printf("Enter x2 for Point #2: ");
    scanf("%lf", &x2);

    printf("Enter y2 for Point #2: ");
    scanf ("%lf", &y2);
    
    
    double width = fabs(x2 - x1);// just incase theres a neg number
    
    printf("Point #1 entered: x1 = %.2lf; y1 = %.2lf\n", x1, y1);
    printf("Point #2 entered: x2 = %.2lf; y2 = %.2lf\n", x2, y2);
    printf("The width of the city encompassed by your request is %.2lf\n", width);
    
    return 3.0;  // about the same as the pow, just finding the names of these things
}

double calculate_height() {
    double x1, y1, x2, y2;
    
    printf("Enter x1 for Point #1: ");
    scanf("%lf", &x1);

    printf("Enter y1 for Point #1: ");
    scanf ("%lf", &y1);
    
    printf("Enter x2 for Point #2: ");
    scanf("%lf", &x2);

    printf("Enter y2 for Point #2: ");
    scanf ("%lf", &y2);
    
     
    double height = fabs(y2 - y1);
    
    printf("Point #1 entered: x1 = %.2lf; y1 = %.2lf\n", x1, y1);
    printf("Point #2 entered: x2 = %.2lf; y2 = %.2lf\n", x2, y2);
    printf("The height of the city encompassed by your request is %.2lf\n", height);
    
    return 1.0;  // just a copy of the last with y instead of x lol
}

double ask_for_user_input() {
    double value;
    scanf("%lf", &value);
    return value;
}
