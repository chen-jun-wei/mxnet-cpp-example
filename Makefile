CC = g++


# Set the mxnet source directory

MXNET = ~/src/mxnet

MXNET_LIB = ${MXNET}/lib

LIBRARY = -L ${MXNET_LIB} \
-l boost_system \
-l boost_filesystem \
-l protobuf \
-l opencv_highgui \
-l opencv_imgcodecs \
-l opencv_imgproc \
-l opencv_core \
-l lmdb \
-l mxnet


#CC_FILE = io.cc  kvstore.cc  ndarray.cc  operator.cc  optimizer.cc  symbol.cc




INCLUDE = -I ./ \
-I /usr/local/include \
-I ${MXNET}/include \
-I ${MXNET}/nnvm/include \
-I ${MXNET}/dmlc-core/include

DEPENDENCIES = shortcut/box.hh shortcut/box.h shortcut/basic.hh shortcut/basic.h

sum: sum.cc

	${CC} sum.cc ${LIBRARY} ${INCLUDE} -o output/sum

topk: topk.cc

	${CC} topk.cc ${LIBRARY} ${INCLUDE} -o output/topk


reshape: reshape.cc

	${CC} reshape.cc ${LIBRARY} ${INCLUDE} -o output/reshape


Mat_NDArray: Mat_NDArray.cc

	${CC} Mat_NDArray.cc ${LIBRARY} ${INCLUDE} -o output/Mat_NDArray
