#
# UDP Simple - basic example (gcc + make)
#

# -----------------=============================== BUILD STAGE ======================-------------------

# Use the 'dev-builder-c' image as the project build stage
FROM test/dev-builder-c AS builder

# IMPORTANT! Do not remove, this ensures fresh app builds
ARG CACHEBUST=0

# Copy (or download/clone) source code into the build stage
COPY src/ /tmp/src/
# Build the app
RUN cd /tmp ; \
    cmake -S src -B build ; \
    cmake --build build ; \
    mkdir /app ; \
    cp build/server /app ; \
    cp build/client /app

# ---------------============================= APP CONTAINER IMAGE ======================-----------------

# Use the 'kiv-psi-base-docker' image
FROM ghcr.io/maxotta/kiv-psi-base-docker:latest

# Copy the built app from the build stage into the app container image
COPY --from=builder /app/ /app/

# Start the simple UDP server
ENTRYPOINT /app/server

#
# EOF
#
