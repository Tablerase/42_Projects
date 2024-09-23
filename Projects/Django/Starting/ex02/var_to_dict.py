
def var_to_dict(input_list: list[tuple]):
  """
  Transform a list of tuple variable into a dict,
  and print the dict in the standard output

  :param input_list: variable to transform, example: [('Hendrix', '1942'), ...]
  :type input_list: list of tuple
  :raise ValueError: when second tuple str value conversion to int fails
  """
  final_dict = {}
  for value, key in input_list:
    try:
      int_key = int(key)
    except ValueError:
      raise ValueError(print(f"{key} cannot be converted into an int"))
    final_dict[int_key] = value
  
  for year, person in final_dict.items():
    print(f"{year} : {person}")

if __name__ == "__main__":
  d = [
    ('Hendrix' , '1942'),
    ('Allman' , '1946'),
    ('King' , '1925'),
    ('Clapton' , '1945'),
    ('Johnson' , '1911'),
    ('Berry' , '1926'),
    ('Vaughan' , '1954'),
    ('Cooder' , '1947'),
    ('Page' , '1944'),
    ('Richards' , '1943'),
    ('Hammett' , '1962'),
    ('Cobain' , '1967'),
    ('Garcia' , '1942'),
    ('Beck' , '1944'),
    ('Santana' , '1947'),
    ('Ramone' , '1948'),
    ('White' , '1975'),
    ('Frusciante', '1970'),
    ('Thompson' , '1949'),
    ('Burton' , '1939')
  ]
  var_to_dict(d)