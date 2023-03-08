FROM alpine:latest AS builder

RUN apk add --no-cache \
    git \
    make \
    musl-dev \
    gcc 

WORKDIR /src

COPY blink/ . 

RUN mkdir obj

RUN make

FROM alpine:latest

WORKDIR /bin

COPY --from=builder /src/blink .

CMD blink
