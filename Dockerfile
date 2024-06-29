# Use an official image as a parent image
FROM ubuntu:24.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    clang \
    libcurl4-openssl-dev \
    libboost-all-dev \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . .

# Create a build directory and navigate to it
RUN mkdir -p build
WORKDIR /app/build

# Configure and build the project
RUN cmake ..
RUN make

# Run the executable
CMD ["./main_api"]
