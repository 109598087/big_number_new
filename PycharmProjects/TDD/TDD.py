import copy
import ttg


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
    temp_and = True
    for bo in inputs_list:
        temp_and = temp_and and bo
    return temp_and


def gate_or(inputs_list):
    temp_or = True
    for bo in inputs_list:
        temp_or = temp_or or bo
    return temp_or


def gate_not(inputs_list):
    return not inputs_list[0]


def find_order_list(list_of_3_s_temp):
    # find order
    list_of_3_s_copy = copy.deepcopy(list_of_3_s_temp)  # for replace
    order_list_temp = list()
    for m in range(len(list_of_3_s_copy)):
        for i in range(len(list_of_3_s_copy)):
            if i + 1 in order_list_temp:
                continue
            count_minus = 0
            for j in range(len(list_of_3_s_copy[i]) - 2):
                temp_str = list_of_3_s_copy[i][j + 1]
                if temp_str.startswith('-'):
                    count_minus += 1
            if count_minus == len(list_of_3_s_copy[i]) - 2:
                order_list_temp.append(i + 1)
                for k in range(len(list_of_3_s_copy)):
                    for l in range(len(list_of_3_s_copy[k]) - 2):
                        if list_of_3_s_copy[k][l + 1].startswith(str(i + 1)):
                            list_of_3_s_copy[k][l + 1] = list_of_3_s_copy[k][l + 1].replace(str(i + 1), '-', 1)
                break
    return order_list_temp


def connect(order_list_temp, list_of_3_s_ordered_temp, inputs_list_of_all_temp, inputs_temp):
    # connect
    # minus(-) ->append
    for i in range(len(list_of_3_s_ordered_temp)):
        for j in range(len(list_of_3_s_ordered_temp[i])):
            temp = list_of_3_s_ordered_temp[i][j]
            if temp.startswith('-'):
                num = int(list_of_3_s_ordered_temp[i][j]) * -1
                inputs_list_of_all_temp[i].append(inputs_temp[num - 1])
    # find end
    end_list = list()
    for i in range(len(order_list_temp)):
        end_list.append(False)

    for num in order_list_temp:
        for i in range(len(list_of_3_s_ordered_temp)):
            for j in range(len(list_of_3_s_ordered_temp[i])):
                if list_of_3_s_ordered_temp[i][j].startswith(str(num)) and len(list_of_3_s_ordered_temp[i][j]) == 3:
                    index_of_output = order_list_temp.index(num)
                    end_list[index_of_output] = True
                    if list_of_3_s_ordered_temp[index_of_output][0] == '1':
                        inputs_list_of_all_temp[i].append(gate_and(inputs_list_of_all_temp[index_of_output]))
                    if list_of_3_s_ordered_temp[index_of_output][0] == '2':
                        inputs_list_of_all_temp[i].append(gate_or(inputs_list_of_all_temp[index_of_output]))
                    if list_of_3_s_ordered_temp[index_of_output][0] == '3':
                        inputs_list_of_all_temp[i].append(gate_not(inputs_list_of_all_temp[index_of_output]))
    return end_list


def truth_table(number):
    list_temp = list()
    for i in range(number):
        list_temp.append(str(i))
    table = ttg.Truths(list_temp)
    list2 = table.as_pandas().values.tolist()
    return list2


##########################################
num_of_inputs, num_of_gates, list_of_3_s = load("file2.txt")
order_list = find_order_list(list_of_3_s)
# list_of_3_s_ordered
list_of_3_s_ordered = list()
for i in range(len(list_of_3_s)):
    list_of_3_s_ordered.append(list_of_3_s[order_list[i] - 1])
# create input_list
truth_table_list = truth_table(num_of_inputs)
for i in range(len(truth_table_list)):
    # create empty input_list[[0],[1],[2]] 0:first do
    inputs_list_of_all = list()
    for j in range(len(order_list)):
        list1 = list()
        inputs_list_of_all.append(list1)
    inputs = list()
    a1 = bool(truth_table_list[i][0])
    print('a1: ', a1)
    b2 = bool(truth_table_list[i][1])
    print('b2: ', b2)
    c3 = bool(truth_table_list[i][2])
    print('c3: ', c3)
    inputs.append(a1)
    inputs.append(b2)
    inputs.append(c3)
    end_list = connect(order_list, list_of_3_s_ordered, inputs_list_of_all, inputs)
    for i in range(len(end_list)):
        if end_list[i]:
            continue
        else:
            if list_of_3_s_ordered[i][0] == '1':
                print(gate_and(inputs_list_of_all[i]))
            if list_of_3_s_ordered[i][0] == '2':
                print(gate_or(inputs_list_of_all[i]))
            if list_of_3_s_ordered[i][0] == '3':
                print(gate_not(inputs_list_of_all[i]))
