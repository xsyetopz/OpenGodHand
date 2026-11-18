# i386 Wine for the SN Systems ee-gcc 2.95.x Windows builds and the i386 Linux ee-gcc 2.96.
FROM i386/debian:bookworm-slim
RUN apt-get update && apt-get install -y --no-install-recommends wine wine32 && rm -rf /var/lib/apt/lists/*
ENV WINEDEBUG=-all WINEPREFIX=/wine
RUN wineboot -i >/dev/null 2>&1 || true
