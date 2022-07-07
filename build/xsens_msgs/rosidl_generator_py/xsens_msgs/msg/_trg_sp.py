# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xsens_msgs:msg/TrgSP.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'stamp'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TrgSP(type):
    """Metaclass of message 'TrgSP'."""

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
                'xsens_msgs.msg.TrgSP')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__trg_sp
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__trg_sp
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__trg_sp
            cls._TYPE_SUPPORT = module.type_support_msg__msg__trg_sp
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__trg_sp

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TrgSP(metaclass=Metaclass_TrgSP):
    """Message class 'TrgSP'."""

    __slots__ = [
        '_stamp',
        '_trig_counter',
    ]

    _fields_and_field_types = {
        'stamp': 'sequence<int32>',
        'trig_counter': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.stamp = array.array('i', kwargs.get('stamp', []))
        self.trig_counter = kwargs.get('trig_counter', int())

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
        if self.trig_counter != other.trig_counter:
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
    def trig_counter(self):
        """Message field 'trig_counter'."""
        return self._trig_counter

    @trig_counter.setter
    def trig_counter(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'trig_counter' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'trig_counter' field must be an integer in [-2147483648, 2147483647]"
        self._trig_counter = value