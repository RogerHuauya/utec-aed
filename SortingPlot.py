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
    fig, axes = plt.subplots(nrows=1, ncols=2, figsize=(12, 6))
    ax = axes[0]
    for (algorithm, file_name) in zip(sorting_algorithms[:2], sorting_algorithms_files[:2]):
        data = pd.read_csv(file_name)
        ax.set_title("Quicksort vs Mergesort")
        ax.set_xlabel("List Size")
        ax.set_ylabel("Time")
        x = np.log10(data["n"])
        y = data["tiempo"]
        ax.plot(x, y, label=algorithm)
        ax.scatter(x, y, color='red', marker='o')

    ax.set_title("QuickSort vs MergeSort")
    ax.set_xlabel("List Size")
    ax.set_ylabel("Time")
    ax.legend()

    ax = axes[1]
    algorithm = sorting_algorithms[2]
    file_name = sorting_algorithms_files[2]
    data = pd.read_csv(file_name)
    ax.set_title(algorithm)
    ax.set_xlabel("List Size")
    ax.set_ylabel("Time")
    x = np.log10(data["n"])
    y = data["tiempo"]
    ax.plot(x, y, label=algorithm)
    ax.scatter(x, y, color='red', marker='o')

    ax.set_title(algorithm)
    ax.set_xlabel("List Size")
    ax.set_ylabel("Time")
    ax.legend()

    plt.tight_layout()
    plt.tight_layout()
    plt.savefig("sorting_algorithms_subplot.png")
    plt.show()

if __name__ == "__main__":
    main()
