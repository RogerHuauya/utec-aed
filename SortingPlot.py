from matplotlib import pyplot as plt
from matplotlib import style
import pandas as pd


def plot(file_name, title):
    """
    Plot a list of numbers.
    """
    data = pd.read_csv(file_name)
    plt.style.use('ggplot')
    plt.title(title)
    plt.xlabel("List Size")
    plt.ylabel("Time")
    plt.plot(data["n"], data["tiempo"], label=title)
    plt.show()
    plt.savefig(file_name[:-4] + ".png")


def main():
    sorting_algorithms = ["QuickSort",
                          #"MergeSort",
                          "InsertionSort",
                          ]
    sorting_algorithms_files = ["QuickSort_times.csv",
                                #"MergeSort_times.csv",
                                "InsertionSort_times.csv",
                                ]

    for (algorithm, file_name) in zip(sorting_algorithms,
                                      sorting_algorithms_files):
        plot(file_name, algorithm)


if __name__ == "__main__":
    main()
