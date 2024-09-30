# https://www.geeksforgeeks.org/python-sort-python-dictionaries-by-key-or-value/

def sorting_dict():
  """
  Sort the musician dictionary by years in ascending order, then by
  alphabetic order for similar years. After sorting display one musician
  per line
  """
  d = {
    'Hendrix' : '1942',
    'Allman' : '1946',
    'King' : '1925',
    'Clapton' : '1945',
    'Johnson' : '1911',
    'Berry' : '1926',
    'Vaughan' : '1954',
    'Cooder' : '1947',
    'Page' : '1944',
    'Richards' : '1943',
    'Hammett' : '1962',
    'Cobain' : '1967',
    'Garcia' : '1942',
    'Beck' : '1944',
    'Santana' : '1947',
    'Ramone' : '1948',
    'White' : '1975',
    'Frusciante': '1970',
    'Thompson' : '1949',
    'Burton' : '1939',
  }
  # sorted ( iterable obj, key to customize the sorting process)
  # return a list of tuples
  ## key is a function that define a custom sort
  ## returns a tuple, this tuple is used to compare firstly years kv[1]
  ## and secondly the alphabetical order kv[0]
  ascending_d = sorted(d.items(), key=lambda kv: (kv[1], kv[0]))
  for musician, year in ascending_d:
    print(musician)

if __name__ == '__main__':
  sorting_dict()