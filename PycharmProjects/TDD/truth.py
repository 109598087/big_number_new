truth = list()  # [inputs, inputs...]
t_f = [False, True]
for i in range(len(t_f)):
    for j in range(len(t_f)):
        for k in range(len(t_f)):
            inputs = list()
            inputs.append(t_f[i])
            inputs.append(t_f[j])
            inputs.append(t_f[k])
            truth.append(inputs)
print(truth)
