from matplotlib import pyplot as plt
from matplotlib import style
import numpy as np

def read_file(file_name):
    """
    Read a file with a list of numbers.
    """
    with open(file_name, 'r') as file:
        lines = file.readlines()[1:]
        split_lines = [line.split(',') for line in lines]
        data = np.array([])
        data = np.array([float(number) for line in split_lines for number in line])
        return data
    
    return None



def plot(file_name, title):
    """
    Plot a list of numbers.
    """
    data = read_file(file_name)
    plt.style.use('ggplot')
    plt.title(title)
    plt.xlabel("Size of the list")
    plt.ylabel("Time")
    plt.plot(data)
    plt.show()
    


def save_plot(file_name, plot_name):
    """
    Plot a list of numbers and save it to a file.
    """
    data = read_file(file_name)
    plt.plot(data)
    plt.savefig(plot_name)



def QuickSortPlot(file_name="QuickSort_times.csv"):
    """
    Plot the time of QuickSort.
    """
    data = read_file(file_name)
    plot(file_name, "QuickSort")
    option = input("Do you want to save the plot? (y/n): ")
    if option == "y":
        plot_name = "QuickSort_times.png"
        save_plot(file_name, plot_name)



def MergeSortPlot(file_name="MergeSort_times.csv"):
    """
    Plot the time of MergeSort.
    """
    data = read_file(file_name)
    plot(file_name, "MergeSort")
    option = input("Do you want to save the plot? (y/n): ")
    if option == "y":
        plot_name = "MergeSort_times.png"
        save_plot(file_name, plot_name)



def InsertionSortPlot(file_name="InsertionSort_times.csv"):
    """
    Plot the time of InsertionSort.
    """
    data = read_file(file_name)
    plot(file_name, "InsertionSort")
    option = input("Do you want to save the plot? (y/n): ")
    if option == "y":
        plot_name = "InsertionSort_times.png"
        save_plot(file_name, plot_name)



def main():
    """
    Main function.
    """


    option = input("Want to see the plot of QuickSort? (y/n): ")
    if option == "y":
        QuickSortPlot()
    
    """
    option = input("Want to see the plot of MergeSort? (y/n): ")
    if option == "y":
        MergeSortPlot()

    """

    option = input("Want to see the plot of InsertionSort? (y/n):")
    if option == "y":
        InsertionSortPlot()

if __name__ == "__main__":
    main()