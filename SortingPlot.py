from matplotlib import pyplot as plt
from matplotlib import style
import pandas as pd
import numpy as np

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
                          "MergeSort",
                          "InsertionSort",
                          ]
    sorting_algorithms_files = ["QuickSort_results.csv",
                                "MergeSort_results.csv",
                                "InsertionSort_results.csv",
                                ]

    for (algorithm, file_name) in zip(sorting_algorithms,
                                      sorting_algorithms_files):
        plt.figure()
        data = pd.read_csv("cmake-build-debug/" + file_name)
        plt.style.use('ggplot')
        plt.title(algorithm)
        plt.xlabel("List Size")
        plt.ylabel("Time")
        x = np.log10(data["n"])
        y = data["tiempo"]
        plt.plot(x, y, label=algorithm)
        plt.scatter(x, y, color='red', marker='o', label='Points')
        plt.savefig(file_name[:-4] + ".png")

    plt.show()

if __name__ == "__main__":
    main()
