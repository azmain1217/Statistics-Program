/*
Developer: 		Syed Azmain
Date: 			March 20, 2018
Description: 	I created this very simple program that calculates various statistics from data supplied. It gives a summary of statistical calculation based on data such as 
				standard deviation,	variance sum of squares, average, and sum. In the future, I plan to add more functionality to this program to calculate correlation 
				coefficient and regression lines.
*/
#include <iostream>
#include <math.h>

using namespace std;
void print_title();
double sum_func(double [], int);
double avg_func(double, double);
double sum_of_squares(double, double, int);
double std_dev_sample(double, int);
double std_dev_population(double, int);
double calc_var(double);
void print(double, double, double, double, double, double, double, double);
void footer();

int main () 
{
	
	int count=0;
	int n;
	double m, sum_num, sum_square_num, sum_squared, std_dev_samp, std_dev_pop, var_sam, var_pop, avg;
	char q='q';
	
	print_title();
	
	cout << "How many numbers are you going to enter? (Please enter -1 if you wish to quit program)" << endl;
	cin >> n;
	
	double num_array[n];
	double num_square_arr[n];

	if(n==-1)
	{
			cout << "You entered -1 to quit program!" << endl;
	}
	else if(n==0 || n==1)
	{
		if (n==0){
			cout << "You have to enter more than " << n << " numbers!" << endl;
		}else{
			cout << "You have to enter more than " << n << " number!" << endl;
		}

	}
	else{
		int while_count=0;
		
		for (int i=0; i<n; i++)
		{
			cout << "Enter num " << while_count+1 << endl;
			count++;
			cin >> m;
			num_array[i] = m;
			num_square_arr[i] = m*m;
			while_count++;
		}
		cout << "These are the " << count << " numbers you entered: ";
		
		for (int i=0; i<n; i++)
		{
			cout << num_array[i] << " ";
		}
		cout << endl;
		
		sum_num = sum_func(num_array, count);    						// stores calculated sum value of all array values
		sum_square_num = sum_func(num_square_arr, count); 				// stores calculated sum value of all array values squared.
		avg = avg_func(sum_num, count); 								// stores calculated avg value
		sum_squared = sum_of_squares(sum_num, sum_square_num, count); 	// stores calculated sum of square value
		std_dev_samp = std_dev_sample(sum_squared, count); 				// stores calculated std deviation sample value
		std_dev_pop = std_dev_population(sum_squared, count); 			// stores std dev population value
		var_sam = calc_var(std_dev_samp); 								// stores variance of sample std dev
		var_pop = calc_var(std_dev_pop); 								// stores variance of population std dev
	
		print(sum_num, sum_square_num, avg, sum_squared, std_dev_samp, std_dev_pop, var_sam, var_pop); calls print function
	}
	
	footer();
	
	return 0;
}
void print_title() // Prints only the title at the top.
{
	cout << "\t\t\t\t\tWELCOME TO THE STATISTICS PROGRAM v1.0" << endl;
	cout << endl;
}
double sum_func (double array_num [], int total)  //This function basically takes an array and total count numbers and calculates
{												  //the sum and sends it back to main
	double s=0;
	for (int i=0; i<total; i++)
	{
		s +=array_num[i];
		
	}
	return s;
	
}
double avg_func(double sum_nums, double total) //This function takes the sum value, and the count to calculate the average and returns to main
{
	double avg_nums;
	avg_nums = sum_nums/total;
	return avg_nums;
		
}
double sum_of_squares(double sum_n, double sum_n_square, int total) // This function takes the sum value, sum of numbers squared value calculated using 'sum_func' and
{																	// calculates the sum of squares value then returns to main.
	double sum_squared, sum_x_squared;
	sum_x_squared = sum_n*sum_n;
	sum_squared = (sum_n_square - (sum_x_squared/total));
	
	return sum_squared;
}
double std_dev_sample(double sum_sq, int total) // This function calculates the standard deviation of a sample, by taking the sum of squares value
{												// and total then sends back to main. Std dev of sample calculated with total minus 1!
	
	double std_dev;
	int sample_size;
	sample_size = total-1;
	std_dev = sqrt(sum_sq/sample_size);
	return std_dev;
}
double std_dev_population(double sum_sq, int total) // This function calculates the standard deviation of a population by taking sum of squares value and total
{													// and sends back to main. Std dev of population calculated with total.
	double std_dev;
	int sample_size;
	sample_size = total;
	std_dev = sqrt(sum_sq/sample_size);
	return std_dev;
}
double calc_var(double std_dev) // This function calculates the standard deviation of population or sample, simply by squaring whichever std dev given to function
{								// and sends back to main.	
	
	double var;
	var = std_dev*std_dev;
	return var;
}
void print(double sum, double sum_square, double avg, double ss, double std_ds, double std_dp, double var_s, double var_p) 
{ // This function basically prints all values that were calculated through other functions such as avg, std dev sample, std dev population, variance, and sum of squares.
	cout << endl;
	cout << endl;
	cout << "=================================================" << endl;
	cout << "SUMMARY OF DATA PROVIDED:" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Sum of numbers: \t\t\t" << sum << endl;
	cout << "Sum of numbers squared: \t\t" << sum_square << endl;
	cout << "Average of numbers: \t\t\t" << avg << endl;
	cout << "Sum of Squares is: \t\t\t" << ss << endl;
	cout << "Standard Deviation of Sample: \t\t" << std_ds << endl;
	cout << "Variance of Sample: \t\t\t" << var_s << endl;
	cout << "Standard Deviation of Population: \t" << std_dp << endl;
	cout << "variance of Population: \t\t" << var_p << endl;
}
void footer () {
	cout << endl;
	cout << "*******************************  Copyright 2018: Syed Azmain, Developer and Student  ********************************" << endl;
}
