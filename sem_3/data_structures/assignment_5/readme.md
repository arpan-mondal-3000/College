### Statement

_Date: 12 Sept, 2024_
Implement the algorithm in C as described below:

**The Problem:** In a clustering problem, you are given n data points, where each data point is represented by 2 numerical attributes a1, a2 and an integer value k. You need to partition the data points into k clusters ( i.e, each data point gets assigned to at most one cluster) such that the data points in a particular cluster are closer (the Euclidean distance between a pair of points) to each other than the points in any other clusters.
(Informally, we want to find k natural clusters from the data set, by looking at which data points are closer to each other. In the attached file you can see there are four clusters, each represented by a different colour)

**Note:**

1. Read n data points from a file.
2. Store n points (a1, a2) in a structure. also keep an additional member to store the Cluster Id for this data point which will be updated during the algorithm

**Algorithm: (K-means clustering)**

1. Randomly generate k cluster centers, i.e generate k different (x,y) pairs.
2. Compute Euclidean distances of between each of the n data points to each of k cluster centers.
3. Determine the minimum distanced cluster center (j) for each data point (i) and assign j as cluster id of data point j.
4. Now compute the coordinates (x,y) of new cluster centers for each of k clusters by taking the mean of all the data points assigned to a particular cluster j.
5. Repeat Steps 2 to 4 as long as the cluster id of data point changes from one iteration to the other.
