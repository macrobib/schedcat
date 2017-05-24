"""Visualize the taskset generated by the taskset generator."""

import matplotlib.pyplot as plt
import json
import numpy as np

class visualize:

    def __init__(self, taskset_dir):
        self.taskset_dir = taskset_dir
        self.taskset = None

    def load_taskset(self):
        """parse the directory and load the taskset from json."""
        pass

    def plot_distribution_prio(self):
        """Plot the task distribution by priority"""
        pass

    def plot_distribution_util(self):
        """Plot the task distribution based on the utilization clusters."""
        pass

    def plot_distribution_crit(self):
        """Plot the task distribution based on the criticality clusters."""
        pass

    def multi_plot_distribution(self):
        """Mosaic overview of the various distributions."""
        pass
