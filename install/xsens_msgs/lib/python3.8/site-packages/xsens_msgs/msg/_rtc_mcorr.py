# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xsens_msgs:msg/RTCMcorr.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'rtcm_data'
# Member 'layout'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RTCMcorr(type):
    """Metaclass of message 'RTCMcorr'."""

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
                'xsens_msgs.msg.RTCMcorr')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rtc_mcorr
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rtc_mcorr
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rtc_mcorr
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rtc_mcorr
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rtc_mcorr

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RTCMcorr(metaclass=Metaclass_RTCMcorr):
    """Message class 'RTCMcorr'."""

    __slots__ = [
        '_rtcm_data',
        '_layout',
    ]

    _fields_and_field_types = {
        'rtcm_data': 'sequence<uint8>',
        'layout': 'sequence<uint8>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.rtcm_data = array.array('B', kwargs.get('rtcm_data', []))
        self.layout = array.array('B', kwargs.get('layout', []))

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
        if self.rtcm_data != other.rtcm_data:
            return False
        if self.layout != other.layout:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def rtcm_data(self):
        """Message field 'rtcm_data'."""
        return self._rtcm_data

    @rtcm_data.setter
    def rtcm_data(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'rtcm_data' array.array() must have the type code of 'B'"
            self._rtcm_data = value
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
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'rtcm_data' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._rtcm_data = array.array('B', value)

    @property
    def layout(self):
        """Message field 'layout'."""
        return self._layout

    @layout.setter
    def layout(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'layout' array.array() must have the type code of 'B'"
            self._layout = value
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
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'layout' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._layout = array.array('B', value)
