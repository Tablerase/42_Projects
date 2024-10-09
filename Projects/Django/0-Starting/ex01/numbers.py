
def read_numbers():
  """
  Open a numbers.txt file, read the numbers it contains
  and display them on the standard output, one per line, without any coma.
  """

  file_to_open = "numbers.txt"
  with open(file_to_open, 'r') as file:
    content = file.read()

  str_numbers_without_comma = content.strip().split(',')
  int_numbers = [int(num.strip()) for num in str_numbers_without_comma]

  for element in int_numbers:
    print(element)

if __name__ == '__main__':
  read_numbers()