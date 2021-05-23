import csv  # writer
import random as r  # randint
import os  # mkdir

NUM_OF_ELEMENTS = [100,1000, 5000, 10000, 25000, 50000, 100000, 300000, 600000, 1000000]
AMOUNT_OF_FOLDERS = 10


def coord_gen():
    x = r.randint(-1e4, 1e4)
    y = r.randint(-1e4, 1e4)
    return x, y


def write_to_file(data_size: int, index: int):
    with open(f'data_{index+1}/{data_size}.csv', 'w', newline='') as csv_file_to_write:
        csv_writer = csv.writer(csv_file_to_write)
        for step in range(data_size):
            x, y = coord_gen()
            csv_writer.writerow([x, y])


def creation_of_only_arslanov_knows_amount_files():
    for i in range(AMOUNT_OF_FOLDERS):
        try:
            os.mkdir(f"data_{i+1}")
        except FileExistsError as err:
            print("Folder exists!")
            return err

        for data_size in NUM_OF_ELEMENTS:
            write_to_file(data_size, i)


if __name__ == '__main__':
    creation_of_only_arslanov_knows_amount_files()
