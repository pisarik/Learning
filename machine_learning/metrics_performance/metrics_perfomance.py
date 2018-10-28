import numpy as np
from sklearn import metrics
from scipy import stats


def confusionMatrixGenerator():
    for a in range(10, 100):
        for b in range(100 - a + 1):
            for c in range(100 - a - b + 1):
                d = 100 - a - b - c
                if a + c != 0 and d != 0:
                    yield np.array([[a, b, a + b],
                                    [c, d, c + d],
                                    [a + c, b + d, 100]]) / 100


def accuracy(con_mat):
    return con_mat[0, 0] + con_mat[1, 1]


def recall(con_mat):
    return con_mat[0, 0] / con_mat[2, 0]


def precision(con_mat):
    return con_mat[0, 0] / con_mat[0, 2]


def fScore(con_mat):
    return stats.hmean([recall(con_mat), precision(con_mat)])


def iRecall(con_mat):
    return con_mat[1, 1] / con_mat[2, 1]


def iPrecision(con_mat):
    return con_mat[1, 1] / con_mat[1, 2]


def sensitivity(con_mat):
    return recall(con_mat)


def specificity(con_mat):
    return iRecall(con_mat)


def iFScore(con_mat):
    return stats.hmean([iRecall(con_mat), iPrecision(con_mat)])


def meanFScore(con_mat):
    return (fScore(con_mat) + iFScore(con_mat)) / 2


def tpr(con_mat):
    return recall(con_mat)


def fpr(con_mat):
    return con_mat[0, 1] / con_mat[2, 1]


def tpa(con_mat):
    return con_mat[0, 0] / con_mat[0, 2]


def fna(con_mat):
    return con_mat[1, 0] / con_mat[1, 2]


def informedness(con_mat):
    return tpr(con_mat) - fpr(con_mat)


def markedness(con_mat):
    return tpa(con_mat) - fna(con_mat)


def matthewsCorrelation(con_mat):
    return stats.gmean([informedness(con_mat), markedness(con_mat)])


def cohensKappa(con_mat):
    etp = con_mat[0, 2] * con_mat[2, 0]
    etn = con_mat[1, 2] * con_mat[2, 1]
    expAcc = etp + etn
    obsAcc = accuracy(con_mat)
    return (obsAcc - expAcc) / (1 - expAcc)


def fleissKappa(con_mat):
    ep = (con_mat[0, 2] + con_mat[2, 0]) / 2
    en = (con_mat[1, 2] + con_mat[2, 1]) / 2
    etp = ep**2
    etn = en**2
    expAcc = etp + etn
    obsAcc = accuracy(con_mat)
    return (obsAcc - expAcc) / (1 - expAcc)


def prevalence(con_mat):
    return con_mat[2, 0]


def bias(con_mat):
    return con_mat[0, 2]


def iPrevalence(con_mat):
    return con_mat[2, 1]


def iBias(con_mat):
    return con_mat[1, 2]


if __name__ == '__main__':
    total = 0
    cond_total = 0

    shift = 0000
    shift_rater = 0000
    scale = 10000
    a = 30 * scale + shift + shift_rater
    b = 50 * scale + shift
    c = 2 * scale + shift_rater
    d = 1000 * scale  # + shift
    conf_matrix = np.array([[a, b, a + b],
                            [c, d, c + d],
                            [a + c, b + d, a + b + c + d]]) / \
                  (a + b + c + d)

    print('MCC', matthewsCorrelation(conf_matrix))
    print('F-score', fScore(conf_matrix))
    print('Sens', sensitivity(conf_matrix), 'Spes', specificity(conf_matrix))
    print('Kc', cohensKappa(conf_matrix))
    print('Kf', fleissKappa(conf_matrix))
    print('Inform', informedness(conf_matrix))

    x = np.zeros(a + b + c + d)
    x[:a + c] = 1
    y = np.zeros(a + b + c + d)
    y[:a + b] = 1

    x -= np.mean(x)
    x /= np.std(x)
    y -= np.mean(y)
    y /= np.std(y)

    print(np.mean(x * y))

    # max_diff = 0
    # for idx, m in enumerate(confusionMatrixGenerator()):
    #     total += 1
    #     diff = abs(cohensKappa(m) - fleissKappa(m))
    #     # if diff >= max_diff:
    #     mcc = matthewsCorrelation(m)
    #     inf = informedness(m)
    #     t = -0.1
    #     if ( # fScore(m) - inf < t and
    #         meanFScore(m) - inf < t and
    #         cohensKappa(m) - inf < t and
    #         fleissKappa(m) - inf < t):
    #         cond_total += 1
    #         max_diff = diff
    #         print('Diff {:.3f}'.format(diff))
    #         print(m*100)
    #         print('Recall       {: .3f}\tPrecision   {: .3f}\t'.format(recall(m), precision(m)))
    #         print('Sensitivity  {: .3f}\tSpecificity {: .3f}'.format(sensitivity(m), specificity(m)))
    #         print('F-Score      {: .3f}\tiF-Score    {: .3f}\tMean F-Score {: .3f}'.format(fScore(m), iFScore(m), meanFScore(m)))
    #         print('CohensKappa  {: .3f}\tFleissKappa {: .3f}'.format(cohensKappa(m), fleissKappa(m)))
    #         print('Informedness {: .3f}\tMarkedness  {: .3f}\tMCC          {: .3f}'.format(informedness(m), markedness(m), matthewsCorrelation(m)))
    #         print()
    # print('Total {}\nConditional total {}'.format(total, cond_total))
