def my_var():
  """
  Declare 9 variables of different types and print them on the standard
  output with there types
  """
  type_int = 42
  type_string = "42"
  type_string_number = "quarante-deux"
  type_float = 42.0
  type_bool = True
  type_list = [42]
  type_dict = {42:42}
  type_tuple = (42,)
  type_set = set()
  print("{} has a type {}".format(type_int, type(type_int)))
  print("{} has a type {}".format(type_string, type(type_string)))
  print("{} has a type {}".format(type_string_number, type(type_string_number)))
  print("{} has a type {}".format(type_float, type(type_float)))
  print("{} has a type {}".format(type_bool, type(type_bool)))
  print("{} has a type {}".format(type_list, type(type_list)))
  print("{} has a type {}".format(type_dict, type(type_dict)))
  print("{} has a type {}".format(type_tuple, type(type_tuple)))
  print("{} has a type {}".format(type_set, type(type_set)))

if __name__ == '__main__':
  my_var()