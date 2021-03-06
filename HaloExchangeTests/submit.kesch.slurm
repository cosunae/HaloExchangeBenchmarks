#!/bin/bash
#SBATCH --job-name=cosmo-e
#SBATCH --nodes=1
#SBATCH --ntasks=8
#SBATCH --ntasks-per-node=8
#SBATCH --ntasks-per-socket=8
#SBATCH --output=test.out
#SBATCH --partition=debug
#SBATCH --time=03:00:00
#SBATCH --gres=gpu:8

EXECUTABLE=$1

source /etc/bashrc
module purge
module load craype-haswell
module load cudatoolkit
module load gcc
#module load mvapich2_gnu/2.0.1_gnu48
module load mvapich2gdr_gnu/2.1
module list -l

export LD_LIBRARY_PATH=${CRAY_LD_LIBRARY_PATH}:${LD_LIBRARY_PATH}
#:/opt/cray/lib64:/usr/lib64:/opt/local/slurm/default/lib64:/opt/cray/netcdf/4.3.2/CRAY/83/lib
echo $LD_LIBRARY_PATH

env | grep OMP_NUM_THREADS
env | grep CRAY_CUDA_PROXY
env | grep CRAY_ACC_NO_ASYNC

# Set this to avoid segmentation faults
ulimit -s unlimited
ulimit -a

# set environmental parameters
#export STELLA_DEBUG=42
export OMP_NUM_THREADS=1
export MV2_ENABLE_AFFINITY=0
export MV2_USE_CUDA=1
export MALLOC_MMAP_MAX_=0
export MALLOC_TRIM_THRESHOLD_=536870912
export COSMO_NPROC_NODEVICE=0
export CUDA_AUTO_BOOST=0
#export MPICH_ASYNC_PROGRESS=1

export SLURM_NPROCS=8

echo '********** Start Run ********* '
echo "Time: `date +%s` s"
export G2G=1

#1D
srun --ntasks=8 ${EXECUTABLE} --nprocx 1 --nprocy 8 --ie 520 --je 350 --enable-GCL --ntracer-perHandler 3 --nGCLHandlers 30 --lperi_y --disable-validation-report --nbl_exchg 2
#2D
srun --ntasks=8  ${EXECUTABLE} --nprocx 2 --nprocy 4 --ie 520 --je 350 --enable-GCL --ntracer-perHandler 3 --nGCLHandlers 30 --lperi_y --disable-validation-report --nbl_exchg 2

echo '********** End Test ********* '

