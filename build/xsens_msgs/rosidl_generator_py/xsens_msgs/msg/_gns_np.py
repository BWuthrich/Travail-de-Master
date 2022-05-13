# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xsens_msgs:msg/GnsNP.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'stamp'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GnsNP(type):
    """Metaclass of message 'GnsNP'."""

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
                'xsens_msgs.msg.GnsNP')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gns_np
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gns_np
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gns_np
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gns_np
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gns_np

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GnsNP(metaclass=Metaclass_GnsNP):
    """Message class 'GnsNP'."""

    __slots__ = [
        '_stamp',
        '_fixtype',
        '_lon',
        '_lat',
        '_height',
        '_h_msl',
        '_h_acc',
        '_v_acc',
        '_vel_n',
        '_vel_e',
        '_vel_d',
        '_s_acc',
    ]

    _fields_and_field_types = {
        'stamp': 'sequence<int32>',
        'fixtype': 'int8',
        'lon': 'double',
        'lat': 'double',
        'height': 'int64',
        'h_msl': 'int64',
        'h_acc': 'int64',
        'v_acc': 'int64',
        'vel_n': 'int64',
        'vel_e': 'int64',
        'vel_d': 'int64',
        's_acc': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.stamp = array.array('i', kwargs.get('stamp', []))
        self.fixtype = kwargs.get('fixtype', int())
        self.lon = kwargs.get('lon', float())
        self.lat = kwargs.get('lat', float())
        self.height = kwargs.get('height', int())
        self.h_msl = kwargs.get('h_msl', int())
        self.h_acc = kwargs.get('h_acc', int())
        self.v_acc = kwargs.get('v_acc', int())
        self.vel_n = kwargs.get('vel_n', int())
        self.vel_e = kwargs.get('vel_e', int())
        self.vel_d = kwargs.get('vel_d', int())
        self.s_acc = kwargs.get('s_acc', int())

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
        if self.fixtype != other.fixtype:
            return False
        if self.lon != other.lon:
            return False
        if self.lat != other.lat:
            return False
        if self.height != other.height:
            return False
        if self.h_msl != other.h_msl:
            return False
        if self.h_acc != other.h_acc:
            return False
        if self.v_acc != other.v_acc:
            return False
        if self.vel_n != other.vel_n:
            return False
        if self.vel_e != other.vel_e:
            return False
        if self.vel_d != other.vel_d:
            return False
        if self.s_acc != other.s_acc:
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
    def fixtype(self):
        """Message field 'fixtype'."""
        return self._fixtype

    @fixtype.setter
    def fixtype(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fixtype' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'fixtype' field must be an integer in [-128, 127]"
        self._fixtype = value

    @property
    def lon(self):
        """Message field 'lon'."""
        return self._lon

    @lon.setter
    def lon(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lon' field must be of type 'float'"
        self._lon = value

    @property
    def lat(self):
        """Message field 'lat'."""
        return self._lat

    @lat.setter
    def lat(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lat' field must be of type 'float'"
        self._lat = value

    @property
    def height(self):
        """Message field 'height'."""
        return self._height

    @height.setter
    def height(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'height' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'height' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._height = value

    @property
    def h_msl(self):
        """Message field 'h_msl'."""
        return self._h_msl

    @h_msl.setter
    def h_msl(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'h_msl' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'h_msl' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._h_msl = value

    @property
    def h_acc(self):
        """Message field 'h_acc'."""
        return self._h_acc

    @h_acc.setter
    def h_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'h_acc' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'h_acc' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._h_acc = value

    @property
    def v_acc(self):
        """Message field 'v_acc'."""
        return self._v_acc

    @v_acc.setter
    def v_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'v_acc' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'v_acc' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._v_acc = value

    @property
    def vel_n(self):
        """Message field 'vel_n'."""
        return self._vel_n

    @vel_n.setter
    def vel_n(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vel_n' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'vel_n' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._vel_n = value

    @property
    def vel_e(self):
        """Message field 'vel_e'."""
        return self._vel_e

    @vel_e.setter
    def vel_e(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vel_e' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'vel_e' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._vel_e = value

    @property
    def vel_d(self):
        """Message field 'vel_d'."""
        return self._vel_d

    @vel_d.setter
    def vel_d(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vel_d' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'vel_d' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._vel_d = value

    @property
    def s_acc(self):
        """Message field 's_acc'."""
        return self._s_acc

    @s_acc.setter
    def s_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 's_acc' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 's_acc' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._s_acc = value
