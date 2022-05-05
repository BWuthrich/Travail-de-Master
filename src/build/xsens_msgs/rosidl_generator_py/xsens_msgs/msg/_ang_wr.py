# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xsens_msgs:msg/AngWR.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'stamp'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AngWR(type):
    """Metaclass of message 'AngWR'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('xsens_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'xsens_msgs.msg.AngWR')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ang_wr
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ang_wr
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ang_wr
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ang_wr
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ang_wr

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AngWR(metaclass=Metaclass_AngWR):
    """Message class 'AngWR'."""

    __slots__ = [
        '_stamp',
        '_gyrx',
        '_gyry',
        '_gyrz',
    ]

    _fields_and_field_types = {
        'stamp': 'sequence<int32>',
        'gyrx': 'double',
        'gyry': 'double',
        'gyrz': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.stamp = array.array('i', kwargs.get('stamp', []))
        self.gyrx = kwargs.get('gyrx', float())
        self.gyry = kwargs.get('gyry', float())
        self.gyrz = kwargs.get('gyrz', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.stamp != other.stamp:
            return False
        if self.gyrx != other.gyrx:
            return False
        if self.gyry != other.gyry:
            return False
        if self.gyrz != other.gyrz:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'stamp' array.array() must have the type code of 'i'"
            self._stamp = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'stamp' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._stamp = array.array('i', value)

    @property
    def gyrx(self):
        """Message field 'gyrx'."""
        return self._gyrx

    @gyrx.setter
    def gyrx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyrx' field must be of type 'float'"
        self._gyrx = value

    @property
    def gyry(self):
        """Message field 'gyry'."""
        return self._gyry

    @gyry.setter
    def gyry(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyry' field must be of type 'float'"
        self._gyry = value

    @property
    def gyrz(self):
        """Message field 'gyrz'."""
        return self._gyrz

    @gyrz.setter
    def gyrz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gyrz' field must be of type 'float'"
        self._gyrz = value
