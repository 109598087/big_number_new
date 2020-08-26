import copy


def load(filename):
    with open(file=filename) as f1:
        all_lines = f1.read()
    all_lines_split = all_lines.split("\n")
    num_inputs = int(all_lines_split[0])
    num_gates = int(all_lines_split[1])
    list_3_s = all_lines_split[2:]
    list_of_3_e_2_d = list()
    for line in list_3_s:
        list_of_3_e_2_d.append(line.split(" "))

    return num_inputs, num_gates, list_of_3_e_2_d


def gate_and(inputs_list):
    temp = True
    for bo in inputs_list:
        temp = temp and bo
    return temp


def gate_or(inputs_list):
    temp = True
    for bo in inputs_list:
        temp = temp or bo
    return temp


def gate_not(input_one):
    return not input_one


#######################################
num_of_inputs, num_of_gates, list_of_3_s = load("file.txt")
list_of_3_s_copy = copy.deepcopy(list_of_3_s)  # for replace

# find order
order_list = list()
for m in range(len(list_of_3_s_copy)):
    for i in range(len(list_of_3_s_copy)):
        if i + 1 in order_list:
            continue
        count_minus = 0
        for j in range(len(list_of_3_s_copy[i]) - 2):
            temp_str = list_of_3_s_copy[i][j + 1]
            if temp_str.startswith('-'):
                count_minus += 1
        if count_minus == len(list_of_3_s_copy[i]) - 2:
            order_list.append(i + 1)
            for k in range(len(list_of_3_s_copy)):
                for l in range(len(list_of_3_s_copy[k]) - 2):
                    if list_of_3_s_copy[k][l + 1].startswith(str(i + 1)):
                        list_of_3_s_copy[k][l + 1] = list_of_3_s_copy[k][l + 1].replace(str(i + 1), '-', 1)
            break

print(list_of_3_s_copy)
print(order_list)
