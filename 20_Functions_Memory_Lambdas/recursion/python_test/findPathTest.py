class Node:
  def __init__(self, name, size = 0, is_dir = True):
    self.name = name
    self.size = size
    self.is_dir = is_dir
    self.children_list = []

def findPath(source, target, current_path = ""):
  current_path =  current_path + "/" + source.name 
  
  if(source.name == target.name):
    return current_path

  for child in source.children_list:
    result = findPath(child, target, current_path)
    if(result):
      return result

  return None


bin = Node("bin")
home = Node("home")
user = Node("user")
notes = Node("notes.txt", 50, False)

user.children_list.append(notes)
home.children_list.append(user)
bin.children_list.append(home)

print(findPath(bin, notes))