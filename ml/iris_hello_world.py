"""
Pre-requisites:
* Install below libraries
    1. matplotlib
    2. pandas
    3. sklearn
"""

import pandas
from pandas.plotting import scatter_matrix
import matplotlib.pyplot as plt
from sklearn import model_selection
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression

# Load dataset
url = "https://raw.githubusercontent.com/jbrownlee/Datasets/master/iris.csv"
names = ['sepal-length', 'sepal-width', 'petal-length', 'petal-width', 'class']
# Read data as CSV from the URL
dataset = pandas.read_csv(url, names=names)

# Understanding dataset

print(dataset.shape)  # Prints no. of rows, attributes

# Sneak peek into the first 10 rows of dataset
print(dataset.head(10))

# Understand count, mean, the min and max values, some percentiles of dataset.
print(dataset.describe())

# Visualise input dataset - useful to understand data distribution pattern

# box and whisker plots - for understanding percentile distribution
dataset.plot(kind='box', subplots=True, layout=(2,2), sharex=False, sharey=False)
plt.show()

# histogram plot - to understand frequency of attributes
dataset.hist()
plt.show()

# scatter plot matrix - to plot all pairs of attributes
scatter_matrix(dataset)
plt.show()

# https://www.youtube.com/watch?v=FLuqwQgSBDw&list=PLupD_xFct8mFDeCqoUAWZpUddeqmT28_L&index=1
# I found this playlist helpful to understand graph in more detail

# Create some models of the data and estimate their accuracy on unseen data

# Split-out validation dataset
array = dataset.values
X = array[:, 0:4]
Y = array[:, 4]
# proportion of the dataset to include in the test split
validation_size = 0.20
# seed used by the random number generator
seed = 7
# Split arrays or matrices into random train and test subsets
X_train, X_validation, Y_train, Y_validation = model_selection.train_test_split(X, Y, test_size=validation_size, random_state=seed)

# Build KNN model and predict accuracy - ref video link below
knn_model = KNeighborsClassifier(n_neighbors=5)
knn_model.fit(X_train, Y_train)
knn_predictions = knn_model.predict(X_validation)
# Calculate accuracy score
print("Accuracy score for KNN with nearest neighbours=5 is ", accuracy_score(Y_validation, knn_predictions))

# Logistic Regression algorithm
lr_model = LogisticRegression()
lr_model.fit(X_train, Y_train)
lr_predictions = lr_model.predict(X_validation)
print("Accuracy score for LR is ", accuracy_score(Y_validation, lr_predictions))

# We can fine tune our parameters in the model to get different accuracy scores
knn_model = KNeighborsClassifier(n_neighbors=100)
knn_model.fit(X_train, Y_train)
knn_predictions = knn_model.predict(X_validation)
print("Accuracy score for KNN with nearest neighbours=100 is ", accuracy_score(Y_validation, knn_predictions))

# In ML, there is no specific model or an algorithm which can give 100% result to every single dataset.
# We need to understand the data before we apply any algorithm and build our model depending on the
# desired result.

'''
References : 
1. https://analyticsindiamag.com/start-building-first-machine-learning-project-famous-dataset/
2. https://machinelearningmastery.com/machine-learning-in-python-step-by-step/
3. https://www.youtube.com/watch?v=FLuqwQgSBDw&list=PLupD_xFct8mFDeCqoUAWZpUddeqmT28_L&index=1
4. K Means clustering : https://www.youtube.com/watch?v=4b5d3muPQmA
5. Random forest : https://www.youtube.com/watch?v=J4Wdy0Wc_xQ 
'''