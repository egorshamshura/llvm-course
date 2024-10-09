import matplotlib.pyplot as plt

# Global variables #

map = {}
data = []

def parse_file(file_name):
  f = open(file_name, "r")
  for line in f:
    data.append(line.strip())

def cnt(ran):
  for i in range(len(data) - ran):
    s = " ".join(data[i:i + ran])
    map[s] = map.get(s, 0) + 1

def main():
  parse_file("../logs/userToInstruction.log")
  cnt(1)
  # cnt(2)
  # cnt(3)
  # cnt(4)
  # cnt(5)
  D = dict(sorted(map.items(), key=lambda item: item[1])[-5:])
  print(D)
  plt.bar(*zip(*D.items()))
  plt.show()
if __name__ == "__main__":
  main()