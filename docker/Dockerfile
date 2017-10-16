FROM ubuntu

RUN apt-get update && apt-get install -y \
  g++ \
  git \
  libqt5websockets5-dev \
  make \
  supervisor \
  pyqt5-examples \
  python3-pyqt5.qtwebsockets \
  qt5-default \
  qt5-qmake \
  xvfb \
  x11vnc \
&& rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/gizero/sip-qtserver-mockup.git
WORKDIR sip-qtserver-mockup
RUN qmake && make

ADD image /

ENV DISPLAY :1

ENTRYPOINT ["/startup.sh"]
