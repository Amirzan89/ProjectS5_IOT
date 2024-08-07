import os
import multiprocessing
from SCons.Script import DefaultEnvironment

env = DefaultEnvironment()

def before_build(source, target, env):
    num_jobs = multiprocessing.cpu_count()
    os.environ['MAKEFLAGS'] = f'-j{num_jobs}'
    print(f"Setting MAKEFLAGS to -j{num_jobs} based on {num_jobs} CPU cores")

env.AddPreAction("build", before_build)