import os

GREEN = '\033[92m'
YELLOW = '\033[93m'
RED = '\033[91m'
ENDCOLOR = '\033[0m'

roll = input("Please enter your roll number here: ")
try:
	os.chdir(f"{roll}")
except:
	print(RED + f"Could not find the directory with your roll number - {roll}" + ENDCOLOR)
	exit(0)

files = sorted(os.listdir())
expected = ['dist', 'hash.c', 'hash.h', 'q1', 'q2', 'q3']
if files != expected:
	print(RED + f"The contents of your root directory are incorrect." + ENDCOLOR)
	print(f"Found: {str(files)}")
	print(f"Expected: {str(expected)}")
	exit(0)

files = sorted(os.listdir("q1"))
if ("main.c" not in files) or ("README.md" not in files):
	print(RED + f"The contents of your q1 directory are incorrect." + ENDCOLOR)
	print(f"Found: {str(files)}")
	print(f"main.c is missing." if "main.c" not in files else "README.md is missing.")
	exit(0)

files = sorted(os.listdir("q2"))
if ("main.c" not in files) or ("README.md" not in files):
	print(RED + f"The contents of your q2 directory are incorrect." + ENDCOLOR)
	print(f"Found: {str(files)}")
	print(f"main.c is missing." if "main.c" not in files else "README.md is missing.")
	exit(0)

files = sorted(os.listdir("q3"))
if "main.c" not in files:
	print(RED + f"The contents of your q2 directory are incorrect." + ENDCOLOR)
	print(f"Found: {str(files)}")
	print(f"main.c is missing.")
	exit(0)

# Question 1

try:
	os.system("g++ ./q1/*.c -fsanitize=address -fsanitize=undefined -o dist/scratch/q1.bin")
except:
	print(RED + "Compilation is failing for Question 1" + ENDCOLOR)
	exit(0)

try:
	os.system("./dist/scratch/q1.bin < ./dist/scratch/tests_1/01 > ./dist/scratch/tests_1/01.o")
	os.system("./dist/scratch/q1.bin < ./dist/scratch/tests_1/02 > ./dist/scratch/tests_1/02.o")
	os.system("./dist/scratch/q1.bin < ./dist/scratch/tests_1/03 > ./dist/scratch/tests_1/03.o")
except:
	print(YELLOW + "Your code is crashing on test input on Question 1" + ENDCOLOR)

# Question 2

try:
	os.system("g++ ./q2/*.c -fsanitize=address -fsanitize=undefined -o dist/scratch/q2.bin")
	os.system("./dist/scratch/checker ./dist/scratch/tests_1/01 ./dist/scratch/tests_1/01.o ./dist/scratch/tests_1/01.a")
	os.system("./dist/scratch/checker ./dist/scratch/tests_1/02 ./dist/scratch/tests_1/02.o ./dist/scratch/tests_1/02.a")
	os.system("./dist/scratch/checker ./dist/scratch/tests_1/03 ./dist/scratch/tests_1/03.o ./dist/scratch/tests_1/03.a")
except:
	print(RED + "Compilation is failing for Question 2" + ENDCOLOR)
	exit(0)

try:
	os.system("./dist/scratch/q2.bin < ./dist/scratch/tests_2/01 > ./dist/scratch/tests_2/01.o")
	os.system("./dist/scratch/checker ./dist/scratch/tests_2/01 ./dist/scratch/tests_2/01.o ./dist/scratch/tests_2/01.a")
except:
	print(YELLOW + "Your code is crashing on test input on Question 2" + ENDCOLOR)

# Question 3

try:
	os.system("g++ ./q3/*.c -fsanitize=address -fsanitize=undefined -o dist/scratch/q3.bin")
except:
	print(RED + "Compilation is failing for Question 3" + ENDCOLOR)
	exit(0)

try:
	os.system("./dist/scratch/q3.bin < ./dist/scratch/tests_3/01 > ./dist/scratch/tests_3/01.o")
	os.system("./dist/scratch/q3.bin < ./dist/scratch/tests_3/02 > ./dist/scratch/tests_3/02.o")
	os.system("./dist/scratch/q3.bin < ./dist/scratch/tests_3/03 > ./dist/scratch/tests_3/03.o")
	os.system("./dist/scratch/checker ./dist/scratch/tests_3/01 ./dist/scratch/tests_3/01.o ./dist/scratch/tests_3/01.a")
	os.system("./dist/scratch/checker ./dist/scratch/tests_3/02 ./dist/scratch/tests_3/02.o ./dist/scratch/tests_3/02.a")
	os.system("./dist/scratch/checker ./dist/scratch/tests_3/03 ./dist/scratch/tests_3/03.o ./dist/scratch/tests_3/03.a")
except:
	print(YELLOW + "Your code is crashing on test input on Question 3" + ENDCOLOR)

# Done
os.chdir("..")
choice = input("Would you like a zip of your submission? (y/N): ")
if choice == "y" or choice == "Y":
	os.system(f"zip -qq -r {roll}.zip {roll}/")
	print(GREEN + f"Thanks! Your submission is valid and is zipped as {roll}.zip" + ENDCOLOR)
else:
	print(GREEN + f"Thanks! Your submission is valid. Please zip and submit." + ENDCOLOR)