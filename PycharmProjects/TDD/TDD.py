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


def gate_not(inputs_list):
    return not inputs_list[0]


##########################################
num_of_inputs, num_of_gates, list_of_3_s = load("file.txt")
gates_list = list()  # from order_list's order
# find order
list_of_3_s_copy = copy.deepcopy(list_of_3_s)  # for replace
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

#############################################
# list_of_3_s_ordered
list_of_3_s_ordered = list()
for i in range(len(list_of_3_s)):
    list_of_3_s_ordered.append(list_of_3_s[order_list[i] - 1])

# create input_list[[0],[1],[2]] 0:first do
inputs_list_of_all = list()
for i in range(len(order_list)):
    list1 = list()
    inputs_list_of_all.append(list1)

# create input_list
inputs = list()
a1 = False
b2 = False
c3 = False
inputs.append(a1)
inputs.append(b2)
inputs.append(c3)

# minus(-) ->append
for i in range(len(list_of_3_s_ordered)):
    for j in range(len(list_of_3_s_ordered[i])):
        temp = list_of_3_s_ordered[i][j]
        if temp.startswith('-'):
            num = int(list_of_3_s_ordered[i][j]) * -1
            inputs_list_of_all[i].append(inputs[num - 1])
# connect
for num in order_list:
    for i in range(len(list_of_3_s_ordered)):
        for j in range(len(list_of_3_s_ordered[i])):
            temp2 = list_of_3_s_ordered[i][j]
            if temp2.startswith(str(num)) and len(temp2) == 3:
                index_of_output = order_list.index(num)
                if list_of_3_s_ordered[index_of_output][0] == '1':
                    inputs_list_of_all[i].append(gate_and(inputs_list_of_all[index_of_output]))
                if list_of_3_s_ordered[index_of_output][0] == '2':
                    inputs_list_of_all[i].append(gate_or(inputs_list_of_all[index_of_output]))
                if list_of_3_s_ordered[index_of_output][0] == '3':
                    inputs_list_of_all[i].append(gate_not(inputs_list_of_all[index_of_output]))

print(inputs_list_of_all)
print(order_list)
print(list_of_3_s_ordered)
print(gate_and(inputs_list_of_all[2]))
# print(gate_not(inputs_list_of_all[4]))
